#include "utils.hpp"

void foo(Box<Object>& object) {
  object->function();
}

Box<Object> bar() {
  return new Object();
}
