#ifndef CODEKATA_CPP_THREAD_POOL_H
#define CODEKATA_CPP_THREAD_POOL_H

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class ThreadPool {
public:
  ThreadPool(size_t);

  template<class F, class... Args>
  auto enqueue(F &&f, Args &&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

  ~ThreadPool();

private:
  std::vector<std::thread> workers_;
  std::queue<std::function<void()>> tasks_;
  std::mutex queue_mutex_;
  std::condition_variable condition_;
  bool stop;
};

// the constructor just launches some amount of workers
inline ThreadPool::ThreadPool(size_t threads)
        : stop(false) {
  for (size_t i = 0; i < threads; ++i)
    workers_.emplace_back(
            [this] {
              for (;;) {
                std::function<void()> task;

                {
                  std::unique_lock<std::mutex> lock(this->queue_mutex_);
                  this->condition_.wait(lock,
                                        [this] { return this->stop || !this->tasks_.empty(); });
                  if (this->stop && this->tasks_.empty())
                    return;
                  task = std::move(this->tasks_.front());
                  this->tasks_.pop();
                }

                task();
              }
            }
    );
}

// add new work item to the pool
template<class F, class... Args>
auto ThreadPool::enqueue(F &&f, Args &&... args)
-> std::future<typename std::result_of<F(Args...)>::type> {
  using return_type = typename std::result_of<F(Args...)>::type;

  auto task = std::make_shared<std::packaged_task<return_type()> >(
          std::bind(std::forward<F>(f), std::forward<Args>(args)...)
  );

  std::future<return_type> res = task->get_future();
  {
    std::unique_lock<std::mutex> lock(queue_mutex_);

    // don't allow enqueueing after stopping the pool
    if (stop)
      throw std::runtime_error("enqueue on stopped ThreadPool");

    tasks_.emplace([task]() { (*task)(); });
  }
  condition_.notify_one();
  return res;
}

// the destructor joins all threads
inline ThreadPool::~ThreadPool() {
  {
    std::unique_lock<std::mutex> lock(queue_mutex_);
    stop = true;
  }
  condition_.notify_all();
  for (std::thread &worker: workers_)
    worker.join();
}

#endif //CODEKATA_CPP_THREAD_POOL_H
