#include <stdexcept>

#include "IntObject.hpp"

IntObject::IntObject(const int &val)
  : object_(val)
{}

int IntObject::get_int() {
  return object_;
}

bool IntObject::get_bool() {
  throw std::runtime_error("Try to get bool via int");
}

std::vector<int> & IntObject::get_int_array() {
  throw std::runtime_error("Try to get array via int");
}

std::vector<bool> & IntObject::get_bool_array() {
  throw std::runtime_error("Try to get array via int");
}