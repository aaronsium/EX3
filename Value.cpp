#include <iostream>
#include "General.h"

Value::Value(double val1)  {
  this->value = val1;
}
double Value ::calculate() {
  return this->value;
}
Value::~Value() {

}
