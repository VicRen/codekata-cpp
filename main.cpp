#include "thread/thread_pool.h"
#include <vector>
#include <iostream>
#include <chrono>

int func() {
  std::cout << "testing" << std::endl;
  return 0;
}

void run(const std::function<int(void)>& func) {
  func();
}

int main() {
  run(func);
  ThreadPool pool(4);
  std::vector<std::future<int>> results;
  for (int i = 0; i < 8; i++) {
    results.emplace_back(
            pool.enqueue([i] {
              std::cout << "hello " << i << std::endl;
              std::this_thread::sleep_for(std::chrono::seconds(1));
              std::cout << "world " << i << std::endl;
              return i*i;
            })
    );
  }

  for (auto && result : results) {
    std::cout << result.get() << ' ';
  }
  std::cout << std::endl;
  return 0;
}