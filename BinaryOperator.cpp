
#include "General.h"
BinaryOperator::BinaryOperator(Expression *right1, Expression *left1) {
  this->right = right1;
  this->left = left1;


}
double BinaryOperator::calculate() {
  return 0;
}
BinaryOperator::~BinaryOperator() {

}

