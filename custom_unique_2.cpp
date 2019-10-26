#include <iostream>

template<class T>
struct smart_ptr {
    smart_ptr() 
        : m_ptr{nullptr} {
    }
    smart_ptr(T* ptr) 
        : m_ptr{ptr} {
    }
//*
    smart_ptr& operator=(const smart_ptr&) = delete;
    smart_ptr& operator=(smart_ptr&& other){
        if(m_ptr) delete m_ptr;
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
        return *this;
    }
//*/
    ~smart_ptr() {
        delete m_ptr;
        m_ptr = nullptr;
    }

    T* get() { 
        return m_ptr; 
    }
private:
    T* m_ptr;
};

struct SomeClass {
    SomeClass() {
        std::cout << "ctor" << std::endl;
    }
    ~SomeClass() {
        std::cout << "dtor" << std::endl;
    }
};

auto main() -> int {
    smart_ptr<SomeClass> ptr1;

    std::cout << "start" << std::endl;
    {
        smart_ptr<SomeClass> ptr2{new SomeClass()};
        //ptr1 = ptr2; //дублируем
        ptr2 = smart_ptr<SomeClass>{new SomeClass()}; // затираем
    }
    std::cout << "end" << std::endl;
    return 0;
}