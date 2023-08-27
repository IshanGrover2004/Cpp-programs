#include <iostream>
#include <thread>

void foo(int x) {
  for (int i = 0; i < x; i++)
    std::cout << i << " ";
  std::cout << "\n";
}

void func() {
  for (int i = 0; i < 50; i++) {
    foo(i);
  }
}

int main() {
  auto start = std::chrono::high_resolution_clock::now();

  func();
  foo(100);

  // std::thread t2(foo, 100);
  // std::thread t1(func);
  //
  // t2.join();
  // t1.join();

  auto end = std::chrono::high_resolution_clock::now();
  const std::chrono::duration<double> duration = end - start;
  std::cout << duration.count() << "s\n";
}
