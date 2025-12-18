#include <iostream>
#include <memory>
#include <string>

class Student {
public:
    std::string name;

    // Constructor
    Student(std::string n) : name(n) {
        std::cout << "[Constructor]: Student " << name << " created.\n";
    }

    // Destructor
    ~Student() {
        std::cout << "[Destructor]: Student " << name << " destroyed.\n";
    }

    void study() {
        std::cout << name << " is studying hard!\n";
    }
};

int main() {
    // 1. Recommended: Using std::make_shared
    // Efficient and safe
    auto studentPtr1 = std::make_shared<Student>("Alice");

    {
        // 2. Share ownership
        std::shared_ptr<Student> studentPtr2 = studentPtr1;
        
        std::cout << "Usage count: " << studentPtr1.use_count() << "\n";
        studentPtr2->study();
    } // studentPtr2 is destroyed here, but the Student object remains

    std::cout << "Usage count after scope: " << studentPtr1.use_count() << "\n";

    return 0;
} // studentPtr1 is destroyed here, Student object is deleted
