#include <iostream>
#include "General.h"

Minus::Minus(Expression *right1, Expression *left1) : BinaryOperator(right1, left1) {

  this->right = right1;
  this->left = left1;
}

double Minus::calculate() {
  return right->calculate()-left->calculate();
}
Minus::~Minus() {

}
