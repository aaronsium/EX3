//
// Created by aharon on 20/12/2019.
//

#include "General.h"

Var::Var() {

}
void Var::SetValue(double value1) {
  Var::value = value1;
}
void Var::SetBoundWay(const string &bound_way1) {
  BoundWay = bound_way1;
}
void Var::SetSim(const string &sim1) {
  Var::sim = sim1;
}
double Var::GetValue() const {
  return value;
}
const string &Var::GetBoundWay() const {
  return BoundWay;
}
const string &Var::GetSim() const {
  return sim;
}
const string &Var::GetName() const {
  return name;
}
void Var::SetName(const string &name1) {
  Var::name = name1;
}

