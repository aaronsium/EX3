//
// Created by aharon on 20/12/2019.
//

#include "General.h"

defineVarCommand::defineVarCommand(unordered_map<string, Var> &varSim,unordered_map<string, Var> &varProgram) {
  this->varSim = &varSim;
  this->varProgram = &varProgram;

}
int defineVarCommand::execute(vector<string> &arguments) {
  Var var1;
  //definition
  //there is binding


  if (arguments[2]=="->" || arguments[2]=="<-") {
    var1.SetBoundWay(arguments[2]);
    var1.SetSim(arguments[4]);
    cout << arguments[1]+" "+var1.GetBoundWay()+ " " + var1.GetSim() << endl;

  }
    // there is not binding
  else {
    var1.SetSim(arguments[1]);
    cout << arguments[1]+var1.GetSim() << endl;
  }

  (*varProgram)[arguments[1]] = var1;
  return 5;
}