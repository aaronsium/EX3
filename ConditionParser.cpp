

#include "General.h"

ConditionParser::ConditionParser(unordered_map<string, Var*> &varSim,unordered_map<string, Var> &varProgram) {
  this->varSim = &varSim;
  this->varProgram = &varProgram;

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

Interpreter* i1 = new Interpreter();
Interpreter* i2 = new Interpreter();
  double A = 0;
  double B = 0;

  //inserting to interpreter map
  insertToMap((*this->varProgram),i1->GetVariablesMap());
  A = i1->interpret(arguments[1])->calculate();
  B = i2->interpret(arguments[3])->calculate();

if(arguments[2] == "=="){
if(A==B){
  return true;
}

}else if(arguments[2] == ">"){

  if(A==B){
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
}else{
  return false;
}


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