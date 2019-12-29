//
// Created by aharon on 26/12/2019.
//

#include "General.h"

ConditionParser::ConditionParser() {


}
int ConditionParser::execute(vector<string> &arguments) {
  return 0;
}

// counting how many commands there are in the condition scope
int ConditionParser::commandsCounter(vector<string> &arguments) {
  int counter = 5;
      while(arguments[counter]!="}"){
        counter++;
      }
      return counter;

}
bool ConditionParser::checkCondition(vector<string> &arguments) {

Interpreter* i1 = new Interpreter();
  double A = 0;
  double B = 0;

  A = i1->interpret(arguments[1])->calculate();
  B = i1->interpret(arguments[3])->calculate();

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