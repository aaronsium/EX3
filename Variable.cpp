//
// Created by aharon on 20/12/2019.
//

#include "General.h"

Variable::Variable() {

}
void Variable::SetValue(double value) {
  Variable::value = value;
}
void Variable::SetBoundWay(const string &bound_way) {
  BoundWay = bound_way;
}
void Variable::SetSim(const string &sim) {
  Variable::sim = sim;
}
double Variable::GetValue() const {
  return value;
}
const string &Variable::GetBoundWay() const {
  return BoundWay;
}
const string &Variable::GetSim() const {
  return sim;
}

