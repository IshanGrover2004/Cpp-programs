#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

double fact(int n) {
  if (n == 0)
    return 1;
  else
    return n * fact(n - 1);
}

int fibo(int n) {
  if (n == 1)
    return 0;
  else if (n == 2)
    return 1;
  else
    return fibo(n - 1) + fibo(n - 2);
}

// Implementing through thread-pool
int main() {
  std::vector<std::thread> threadPool(30);
  // how can i store the value of fact coming from thread in threadPool
  for (int i = 0; i < 5; i++)
    threadPool[i] = std::thread(fact, std::ref(i));

  for (int i = 0; i < 30; i++)
    threadPool[i].join();
}

/*
int main() {
  int n = 30;
  auto factorial = std::async(std::launch::async, fact, std::ref(n));

  auto fibonacci = std::async(std::launch::async, fibo, std::ref(n));

  std::cout << "Factorial of " << n << ": " << factorial.get() << std::endl;
  std::cout << "Fibonacci of " << n << ": " << fibonacci.get() << std::endl;

  return 0;
}
*/
