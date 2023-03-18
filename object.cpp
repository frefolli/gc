#include "object.hpp"
#include <cstdio>

Object::Object() {
  std::printf("object constructor!\n");
}

Object::~Object() {
  std::printf("object destructor!\n");
}

void Object::function() {
  std::printf("object function!\n");
}
