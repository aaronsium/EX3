#include <iostream>
#include "General.h"

UMinus::UMinus(Expression *exp1) : UnaryOperator(exp1) {
}

double UMinus::calculate() {
  return this->exp->calculate()*(-1);
}
UMinus::~UMinus() {

}
