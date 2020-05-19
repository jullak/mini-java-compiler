#pragma once

#include "BaseObject.hpp"

class IntArrayObject : public BaseObject {
public:
  explicit IntArrayObject(const int & size);

  int get_int() override;
  bool get_bool() override;
  std::vector<int> & get_int_array() override;
  std::vector<bool> & get_bool_array() override;

  bool is_int() override;
  bool is_bool() override;
  bool is_int_array() override;
  bool is_bool_array() override;

  void set_int(const int & val) {}
  void set_bool(const bool & val) {}
private:
  std::vector<int> object_;
};