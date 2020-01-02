//
// Created by aharon on 20/12/2019.
//

#include "General.h"

defineVarCommand::defineVarCommand(unordered_map<string, Var> varSim,unordered_map<string, Var> varProgram) {
  this->varSim = varSim;
  this->varProgram = varProgram;

}
int defineVarCommand::execute(vector<string> &arguments) {
  Var var1;
  //definition
  //there is binding
  cout << "chack1" << endl;

  if (arguments[1]=="->" || arguments[1]=="<-") {
    var1.SetBoundWay(arguments[1]);
    var1.SetSim(arguments[2]);
  }
    // there is not binding
  else {
    var1.SetSim(arguments[1]);
  }

  varProgram[arguments[0]] = var1;
  return 5;
}