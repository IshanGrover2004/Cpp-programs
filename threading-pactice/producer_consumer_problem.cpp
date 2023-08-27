#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

// Buffer for producer & consumer
std::queue<int> buffer;

int consumer_count = 0;
int producer_count = 0;

// Max Buffer size can be added.
#define MAX_BUFFER_SIZE 50

// Mutex for locking
std::mutex m;

// Condition variable for condition check
std::condition_variable cv;

// Producer adding element in buffer
void producer();

// Consumer popping the produced data from buffer
void consumer();

// main thread
int main() {
  std::thread t_producer(producer);
  std::thread t_consumer(consumer);

  t_producer.join();
  t_consumer.join();
}

/*
// **Problem** --> On running, produce will produce until max_buffer_size and
// then consumer will consume till buffer is empty

// Using Normal locking
void producer() {
  while (buffer.size() < MAX_BUFFER_SIZE) {
    std::lock_guard<std::mutex> lock(m);
    buffer.push(1);
    producer_count++;
    std::cout << "Produced " << producer_count << "\n";
  }
}

void consumer() {
  while (buffer.size() > 0) {
    std::lock_guard<std::mutex> lock(m);
    buffer.pop();
    consumer_count++;
    std::cout << "consumed..." << consumer_count << "\n";
  }
}
*/

// Using condition_variable
void producer() {
  while (buffer.size() < MAX_BUFFER_SIZE) {
    m.lock();
    buffer.push(1);
    m.unlock();
    cv.notify_one();
    producer_count++;
    std::cout << "Produced " << producer_count << "\n";
  }
}

void consumer() {
  while (1) {
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, [] { return buffer.size() > 0; });
    buffer.pop();
    consumer_count++;
    std::cout << "Consumed " << consumer_count << "\n";
  }
}
