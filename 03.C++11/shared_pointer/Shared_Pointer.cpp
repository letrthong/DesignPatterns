#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int x) : value(x) {
        std::cout << "MyClass constructed with value " << value << std::endl;
    }
    ~MyClass() {
        std::cout << "MyClass destroyed" << std::endl;
    }
    void show() const {
        std::cout << "Value: " << value << std::endl;
    }
private:
    int value;
};

int main() {
    // Create a shared pointer using make_shared
    std::shared_ptr<MyClass> ptr = std::make_shared<MyClass>(42);

    // Use the object
    ptr->show();

    // Shared pointer automatically deletes the object when no longer used
    return 0;
}
