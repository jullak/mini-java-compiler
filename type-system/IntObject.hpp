#pragma once

#include "BaseObject.hpp"

class IntObject : public BaseObject {
public:
  explicit IntObject(const int & val);

  int get_int() override;
  bool get_bool() override;
  std::vector<int> & get_int_array() override;
  std::vector<bool> & get_bool_array() override;
private:
  int object_;
};