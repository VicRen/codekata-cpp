#ifndef CODEKATA_CPP_HILEIA_THREAD_H
#define CODEKATA_CPP_HILEIA_THREAD_H

#include <vector>
#include <queue>
#include <memory>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <stdexcept>

class HiLeiaThread {
public:
  HiLeiaThread();

  ~HiLeiaThread();

  template<class F, class... Args>
  auto Post(F &&f, Args &&... args) -> std::future<typename std::result_of<F(Args...)>::type>;

private:
  std::unique_ptr<std::thread> thread_;
  std::queue<std::function<void()>> tasks_;
  std::mutex queue_mutex_;
  std::condition_variable condition_;
  bool stop;
};

inline HiLeiaThread::HiLeiaThread() : stop(false) {
  thread_ = std::make_unique<std::thread>(std::thread([this] {
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
  }));
}

template<class F, class... Args>
inline auto HiLeiaThread::Post(F &&f, Args &&... args) -> std::future<typename std::result_of<F(Args...)>::type> {
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

inline HiLeiaThread::~HiLeiaThread() {
  {
    std::unique_lock<std::mutex> lock(queue_mutex_);
    stop = true;
  }
  condition_.notify_all();
  thread_->join();
}

#endif //CODEKATA_CPP_HILEIA_THREAD_H
