#include <iostream>
#include "General.h"

Div::Div(Expression *right1, Expression *left1) : BinaryOperator(right1, left1) {
  this->right = right1;
  this->left = left1;
}
double Div::calculate() {
  if(left->calculate()!= 0) {
    return right->calculate()/left->calculate();
  }else{
    throw "can't divide by 0";
  }
}
Div::~Div() {

}
