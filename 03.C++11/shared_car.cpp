#include <iostream>
#include <memory> // Thư viện bắt buộc để dùng smart pointers
#include <string>

class Car {
public:
    std::string model;
    int year;

    Car(std::string m, int y) : model(m), year(y) {
        std::cout << "Car " << model << " da duoc tao.\n";
    }

    ~Car() {
        std::cout << "Car " << model << " da bi huy.\n";
    }

    void drive() {
        std::cout << "Dang lai xe " << model << " doi " << year << "\n";
    }
};

int main() {
    // Sử dụng std::make_shared
    // Tham số truyền vào make_shared sẽ được chuyển thẳng đến Constructor của Car
    std::shared_ptr<Car> myCar = std::make_shared<Car>("Toyota", 2023);

    myCar->drive();

    std::cout << "So luong chu so huu: " << myCar.use_count() << "\n";

    {
        std::shared_ptr<Car> anotherPtr = myCar; // Chia sẻ quyền sở hữu
        std::cout << "So luong chu so huu sau khi copy: " << myCar.use_count() << "\n";
    } // anotherPtr bị hủy ở đây, nhưng đối tượng Car vẫn còn

    std::cout << "So luong chu so huu cuoi cung: " << myCar.use_count() << "\n";

    return 0;
} // myCar bị hủy ở đây, đối tượng Car chính thức bị xóa khỏi bộ nhớ
