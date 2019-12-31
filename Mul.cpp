#include <iostream>
#include "General.h"

Mul::Mul(Expression *right1, Expression *left1) : BinaryOperator(right1, left1) {
  this->right = right1;
  this->left = left1;
}
double Mul::calculate() {
 return right->calculate()*left->calculate();
}
Mul::~Mul() {

}
