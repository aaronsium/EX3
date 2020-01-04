//
// Created by aharon on 20/12/2019.
//

#include "General.h"

Var::Var() {

}
void Var::SetValue(double value) {
  Var::value = value;
}
void Var::SetBoundWay(const string &bound_way) {
  BoundWay = bound_way;
}
void Var::SetSim(const string &sim) {
  Var::sim = sim;
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
void Var::SetName(const string &name) {
  Var::name = name;
}

