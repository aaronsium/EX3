//
// Created by aharon on 20/12/2019.
//

#include "General.h"

defineVarCommand::defineVarCommand(unordered_map<string, Variable> varSim,
                                   unordered_map<string, Variable> varProgram,
                                   ) {
  this->varSim = varSim;
  this->varProgram = varProgram;

}
int defineVarCommand::execute(vector<string> &arguments) {
  Variable var1;
  //definition
  //there is binding
  if (arguments[1]=="->" || arguments[1]=="<-") {
    var1.SetBoundWay(arguments[1]);
    var1.SetSim(arguments[2]);
  }
    // there is not binding
  else {
    var1.SetSim(arguments[1]);
  }

  varProgram[arguments[0]] = var1;
}