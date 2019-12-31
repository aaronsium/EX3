#include <iostream>
#include "General.h"

UPlus::UPlus(Expression *exp1) : UnaryOperator(exp1) {
  this->exp = exp1;
}
double UPlus::calculate() {
  return this->exp->calculate()*(1);
}
UPlus::~UPlus() {

}
