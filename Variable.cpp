//
// Created by aharon on 07/11/2019.
//
#include <iostream>
#include "General.h"

// constructors ,getters and setters
Variable::Variable(string name1, double value1) {
  this->name = name1;
  this->value = value1;
}
void Variable::setName(const string &name1) {
  Variable::name = name1;
}
void Variable::setValue(double value1) {
  Variable::value = value1;
}

const string &Variable::getName() const {
  return name;
}

double Variable::getValue() const {
  return value;
}

//functions's implimentation
double Variable::calculate() {
  return this->value;
}
Variable &Variable::operator++() {
  Variable *temp = new Variable(this->getName(), this->getValue() + 1.0);
  return *temp;

}
Variable &Variable::operator--() {
  Variable *temp = new Variable(this->getName(), this->getValue() - 1.0);
  return *temp;

}

Variable &Variable::operator++(int) {
  Variable *temp = new Variable(this->getName(), this->getValue() + 1.0);
  return *temp;

}
Variable &Variable::operator--(int) {
  Variable *temp = new Variable(this->getName(), this->getValue() - 1.0);
  return *temp;

}
Variable &Variable::operator+=(double v1) {
  Variable *v2 = new Variable(this->getName(), this->getValue() + v1);
  return *v2;

}
Variable &Variable::operator-=(double v1) {
  Variable *v2 = new Variable(this->getName(), this->getValue() - v1);
  return *v2;
}
Variable::~Variable() {

}




