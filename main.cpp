#include <cstdio>
#include <stdexcept>
#include "object.hpp"
#include "utils.hpp"

int main(void) {
  Box<Object> object = bar();

  Box<Object> nullObject = nullptr;
  try {
    foo(nullObject);
    throw std::runtime_error("ShouldFailException");
  } catch(std::runtime_error& err) {
    std::printf("runtime_error: %s\n", err.what());
  }
}
