

#include "General.h"

ConditionParser::ConditionParser(unordered_map<string, Var*> &varSim1,unordered_map<string, Var> &varProgram1) {
  this->varSim = &varSim1;
  this->varProgram = &varProgram1;

}
int ConditionParser::execute(vector<string> &arguments) {
  return 0;
}

// counting how many commands there are in the condition scope
int ConditionParser::commandsCounter(vector<string> &arguments) {
  int counter = 0;
      while(arguments[counter]!="}"){
        counter++;
      }
      return (counter);

}
bool ConditionParser::checkCondition(vector<string> &arguments) {

Interpreter i1 ;
Interpreter i2;

  //inserting to interpreter map
  insertToMap((*this->varProgram),i1.GetVariablesMap());
  Expression *x = i1.interpret(arguments[1]);
  Expression *y = i2.interpret(arguments[3]);
  double A = x->calculate();
  double B = y->calculate();
  if(arguments[2] == "=="){
if(A==B){
  return true;
}

}else if(arguments[2] == ">"){

  if(A>B){
    return true;
  }

}else if(arguments[2] == "<"){

  if(A<B){
    return true;
  }

}else if(arguments[2] == ">=") {

  if(A>=B){
    return true;
  }

}else if(arguments[2] == "<="){

  if(A<=B){
    return true;
  }
}
loop = false;
  return false;

}

void ConditionParser::insertToMap(unordered_map<string, Var> &sourceMap, map<string,string> &destMap) {
  //iterate over the sourceMap and copping each element to destMap
  for (auto const& x : sourceMap)
  {
    //convert the value from double to string.
    ostringstream strs;
    strs << x.second.GetValue();
    string value = strs.str();
    //insertion
    destMap[x.first]=value;
  }

}