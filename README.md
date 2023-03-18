# Garbage Collection by Wrapping Pointers

The header file "gc.hpp" defines a class `Box<T>` that wraps and handles (auto-destructing the pointer if now moved) a pointer of a generic `T` typename.

The class `Box<T>` implements copy constructor, move constructor, smart dereference and throws an `std::runtime_error` if a dereference against a `nullptr` occurs. Segfault is no more!

from `utils.cpp`:


```cpp
void foo(Box<Object>& object) {
  object->function();
}

Box<Object> bar() {
  return new Object();
}
```

from `main.cpp`:

```cpp
int main() {
  Box<Object> object = bar();
  Box<Object> nullObject = nullptr;
  try {
    foo(nullObject);
    throw std::runtime_error("ShouldFailException");
  } catch(std::runtime_error& err) {
    std::printf("runtime_error: %s\n", err.what());
  }
}
```
