//
// Created by aharon on 26/12/2019.
//
#include "General.h"

loopCommands::loopCommands() {

}

int loopCommands::execute(vector<string> &arguments) {
  //condition is true -> jump 5 steps forward(into the scope)
  if(condition){
    return 5;
  }
    //condition is false -> jump command's quantity steps forward(out of the scope)
  else{
    // added 1 more for the "}"
    return (commandsCounter(arguments)+1);
  }

}



