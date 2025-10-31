//https://en.cppreference.com/w/cpp/atomic/atomic
#include <atomic>
#include <iostream>

int main() {
    std::atomic<int> counter(0);

    counter++;  // atomic increment
    std::cout << "Counter: " << counter.load() << std::endl;

    return 0;
}
