https://www.onlinegdb.com/online_c++_compiler

#include <iostream>
#include <string>
#include <map>
#include <functional>

// ===== Base Product Interface =====
class Product {
public:
    virtual void use() = 0;
    virtual ~Product() {}
};

// ===== Factory Registry =====
class FactoryRegistry {
public:
    using CreatorFunc = std::function<Product*()>;

    static FactoryRegistry& instance() {
        static FactoryRegistry registry;
        return registry;
    }

    void registerFactory(const std::string& name, CreatorFunc func) {
        creators[name] = func;
    }

    Product* create(const std::string& name) {
        auto it = creators.find(name);
        if (it != creators.end()) {
            return it->second();
        }
        return nullptr;
    }

private:
    std::map<std::string, CreatorFunc> creators;
};

// ===== Macro for Registration =====
#define REGISTER_PRODUCT(class_name) \
    namespace { \
        struct class_name##FactoryRegister { \
            class_name##FactoryRegister() { \
                FactoryRegistry::instance().registerFactory(#class_name, []() -> Product* { return new class_name(); }); \
            } \
        }; \
        static class_name##FactoryRegister global_##class_name##FactoryRegister; \
    }

// ===== Concrete Products =====
class FishFeeder : public Product {
public:
    void use() override {
        std::cout << "Feeding fish..." << std::endl;
    }
};
REGISTER_PRODUCT(FishFeeder)

class WaterFilter : public Product {
public:
    void use() override {
        std::cout << "Filtering water..." << std::endl;
    }
};
REGISTER_PRODUCT(WaterFilter)

class OxygenPump : public Product {
public:
    void use() override {
        std::cout << "Pumping oxygen..." << std::endl;
    }
};
REGISTER_PRODUCT(OxygenPump)

// ===== Main Function =====
int main() {
    std::string input;
    while (true) {
        std::cout << "\nEnter product name (FishFeeder, WaterFilter, OxygenPump) or 'exit': ";
        std::getline(std::cin, input);
        if (input == "exit") break;

        Product* p = FactoryRegistry::instance().create(input);
        if (p) {
            p->use();
            delete p;
        } else {
            std::cout << "Unknown product: " << input << std::endl;
        }
    }

    return 0;
}
