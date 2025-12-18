#include <iostream>
#include <memory>
#include <vector>

class Task {
public:
    int id;
    Task(int i) : id(i) {
        std::cout << "[Constructor]: Task " << id << " allocated.\n";
    }
    ~Task() {
        std::cout << "[Destructor]: Task " << id << " deallocated.\n";
    }
};

int main() {
    // 1. Create a standard allocator for Task objects
    std::allocator<Task> myAlloc;

    // 2. Use allocate_shared instead of make_shared
    // Syntax: std::allocate_shared<Type>(Allocator, Constructor_Args...)
    auto taskPtr = std::allocate_shared<Task>(myAlloc, 101);

    std::cout << "Task ID: " << taskPtr->id << "\n";
    std::cout << "Usage count: " << taskPtr.use_count() << "\n";

    return 0;
}
