//
// Created by aharon on 26/12/2019.
//
#include "General.h"

loopCommands::loopCommands(unordered_map<string, Var*> &var_sim,
                           unordered_map<string, Var> &var_program) : ConditionParser(var_sim, var_program) {

}

int loopCommands::execute(vector<string> &arguments) {
  stepsLoop = commandsCounter(arguments);
  //condition is true -> jump 5 steps forward(into the scope)
  if(checkCondition(arguments)){
    loop = true;
    this->condition = true;
    return 5;
  }
    //condition is false -> jump command's quantity steps forward(out of the scope)
  else{
    loop==false;
    return stepsLoop;
  }

}



