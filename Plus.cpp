#include <iostream>
#include "General.h"

Plus::Plus(Expression *right1, Expression *left1) : BinaryOperator(right1, left1) {
  this->right = right1;
  this->left = left1;
}
double Plus::calculate() {
  return right->calculate()+left->calculate();
}
Plus::~Plus() {

}
