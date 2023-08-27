#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

std::mutex m;
int current_balance = 0;
std::condition_variable cv;

void addMoney(int amount) {
  m.lock();
  current_balance += amount;
  m.unlock();
  cv.notify_one();
  std::cout << "Amount added: $" << amount << std::endl;
}

void withdrawMoney(int amount) {
  std::unique_lock<std::mutex> lock(m);
  cv.wait(lock, [&] { return current_balance > amount; });
  current_balance -= amount;
  std::cout << "Amount deducted: $" << amount << std::endl;
}

int main() {
  std::thread t1(addMoney, 500);
  std::thread t2(withdrawMoney, 100);

  t1.join();
  t2.join();

  std::cout << "Current balance " << current_balance << "\n";
}
