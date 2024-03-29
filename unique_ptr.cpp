#include <cassert>
#include <functional>
#include <iostream>
#include <memory>

int * init() {
    std::cout << "init" << std::endl;
    return new int{13};
}
void deinit(int *ptr) {
    std::cout << "deinit" << std::endl;
    delete ptr;
}

int main() {

    std::unique_ptr<int> ptr{new int{10}};
    assert(ptr);
    assert(*ptr == 10);
    assert(*ptr.get() == 10);
    std::cout << "sizeof(ptr) = " << sizeof(ptr) << std::endl;

    auto ptr2 = std::make_unique<int>(42);
    std::cout << "sizeof(ptr2) = " << sizeof(ptr2) << std::endl << std::endl;

    {
        std::unique_ptr<int, decltype(&deinit)> ptr3{init(), &deinit};
        std::cout << "sizeof(ptr3) = " << sizeof(ptr3) << std::endl;
    }
    std::cout << "after scope" << std::endl << std::endl;

    struct Deleter {
        void operator()(int * ptr) {
            std::cout << "Deleter::operator()" << std::endl;
            deinit(ptr);
        }
    };
    {
        std::unique_ptr<int, Deleter> ptr4{init()};
        std::cout << "sizeof(ptr4) = " << sizeof(ptr4) << std::endl;

        std::unique_ptr<int, Deleter> ptr44{init(), Deleter{}};
        std::cout << "sizeof(ptr44) = " << sizeof(ptr44) << std::endl;
    }
    std::cout << "after scope" << std::endl << std::endl;

    {
        std::unique_ptr<int, std::function<void(int*)>> 
            ptr5{init(), [](int *ptr) {deinit(ptr);}};
        std::cout << "sizeof(ptr5) = " << sizeof(ptr5) << std::endl;
        std::cout << "sizeof(std::function<void()>{}) = " << sizeof(std::function<void()>{}) << std::endl;
    }
    std::cout << "after scope" << std::endl << std::endl;

    {
        auto deleter = [](int * ptr) { deinit(ptr); };
        std::unique_ptr<int, decltype(deleter)> ptr6{init(), deleter};
        std::cout << "sizeof(ptr6) = " << sizeof(ptr6) << std::endl;
        std::cout << "sizeof(deleter) = " << sizeof(deleter) << std::endl;
    }
    std::cout << "after scope" << std::endl << std::endl;

    {
        int fakeValue = 42;
        auto deleter2 = [&fakeValue](int * ptr) { deinit(ptr); };
        std::unique_ptr<int, decltype(deleter2)> ptr7{init(), deleter2};
        std::cout << "sizeof(ptr7) = " << sizeof(ptr7) << std::endl;
        std::cout << "sizeof(deleter) = " << sizeof(deleter2) << std::endl;
    }
    std::cout << "after scope" << std::endl << std::endl;

    return 0;
}