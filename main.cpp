#include "thread/thread_pool.h"
#include "thread/hi_thread.h"
#include <vector>
#include <iostream>
#include <chrono>

class A {
  virtual void OnTesting() = 0;
};

class B {
public:
  virtual void OnTesting(int x) {
    std::cout << "B Testing" << std::endl;
  }
};

class C : public A, B {
public:
  int Func() {
    std::cout << "Func running" << std::endl;
    return 0;
  }

  void OnTesting() override {
    std::cout << "Testing" << std::endl;
    OnTesting(1);
  }

private:
  void OnTesting(int x) override {
    B::OnTesting(x);
  }
};

int func() {
  std::cout << "testing" << std::endl;
  return 0;
}

using Runnable = std::function<int(void)>;

void run(const Runnable &func) {
  func();
}

class Callback {
public:
  void OnCallback() {
    std::cout << __FUNCTION__ << std::endl;
    std::cout << "thread:" << std::this_thread::get_id() << std::endl;
  }
};

int main() {
  C c;
  c.OnTesting();
  run(*(new Runnable{[&c] { return c.Func(); }}));
  auto f = []() -> int {
    std::cout << "closure running" << std::endl;
  };
  run(*(new Runnable(f)));
//  ThreadPool pool(4);
//  std::vector<std::future<int>> results;
//  for (int i = 0; i < 8; i++) {
//    results.emplace_back(
//            pool.enqueue([i] {
//              std::cout << "hello " << i << std::endl;
//              std::this_thread::sleep_for(std::chrono::seconds(1));
//              std::cout << "world " << i << std::endl;
//              return i * i;
//            })
//    );
//  }
//
//  pool.enqueue([]{
//    std::cout << "--------------" << std::endl;
//  });

//  for (auto &&result: results) {
//    std::cout << result.get() << ' ';
//  }
  std::cout << std::endl;
  Callback callback;
  auto callback2 = new Callback;
  std::cout << "thread:" << std::this_thread::get_id() << std::endl;
  HiThread thread;
  thread.Post([&callback, callback2]{
    std::cout << "thread:" << std::this_thread::get_id() << std::endl;
    std::cout << "--------------" << std::endl;
    callback.OnCallback();
    callback2->OnCallback();
  });

  std::string cmd;
  std::getline(std::cin, cmd);
  return 0;
}