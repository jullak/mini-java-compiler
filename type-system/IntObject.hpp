#pragma once

#include "BaseObject.hpp"

class IntObject : public BaseObject {
public:
  explicit IntObject(const int & val);

  int get_int() override;
  bool get_bool() override;
  std::vector<int> & get_int_array() override;
  std::vector<bool> & get_bool_array() override;

  bool is_int() override;
  bool is_bool() override;
  bool is_int_array() override;
  bool is_bool_array() override;

  void set_int(const int & val) override;
  void set_bool(const bool & val) override;
private:
  int object_;
};