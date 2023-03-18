#ifndef GC_HPP
#define GC_HPP
#include <cstdio>
#include <stdexcept>

template<typename T>
class Box {
  T* ptr = nullptr;

  public:
    Box(T* ptr) {
      std::printf("box constructor!\n");
      this->ptr = ptr;
    }

    Box(Box<T>&& box) {
      std::printf("box move constructor!\n");
      this->ptr = box.ptr;
      box.ptr = nullptr;
    }

    Box(Box<T>& box) {
      std::printf("box copy constructor!\n");
      this->ptr = box.ptr;
      box.ptr = nullptr;
    }

    ~Box() {
      std::printf("box destructor!\n");
      if (this->ptr != nullptr) {
        delete this->ptr;
      }
    }

    T* operator->() {
      if (this->ptr == nullptr) {
        throw std::runtime_error("NullPointerException");
      }
      return this->ptr;
    }

    T& operator*() {
        throw std::runtime_error("NullPointerException");
      return *(this->ptr);
    }
};

#endif
