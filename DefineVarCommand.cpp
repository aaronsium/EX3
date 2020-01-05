//
// Created by aharon on 20/12/2019.
//
#include "General.h"

DefineVarCommand::DefineVarCommand(unordered_map<string, Var*> &varSim,unordered_map<string, Var> &varProgram) {
  this->varSim=&varSim;
  this->varProgram = &varProgram;

}
int DefineVarCommand::execute(vector<string> &arguments) {
  Var var1;
  //definition
  //there is binding

  var1.SetName(arguments[1]);
  if (arguments[2]=="->" || arguments[2]=="<-") {
    var1.SetBoundWay(arguments[2]);
    string sim = arguments[4];
    sim.erase(std::remove(sim.begin(), sim.end(), '"'), sim.end());
    string simFix ;
    simFix = sim.substr(1);
    var1.SetSim(simFix);
    cout << arguments[1]+" "+var1.GetBoundWay()+ " " + var1.GetSim() << endl;

  }
        //if it's assignment operation
  else if (arguments[2]=="=") {

    Interpreter i1;
    insertToMap((*varProgram),i1.GetVariablesMap());
    var1.SetValue(i1.interpret(arguments[3])->calculate());
  }
    // there is not binding
  else {
    var1.SetSim(arguments[1]);
    cout << arguments[1]+var1.GetSim() << endl;
  }

  (*varProgram)[arguments[1]] = var1;
  (*varSim)[(*varProgram)[arguments[1]].GetSim()] = &(*varProgram)[arguments[1]];

  if(arguments[2]=="="){
    return 4;
  }else {
    return 5;
  }
}
void DefineVarCommand::insertToMap(unordered_map<string, Var> &sourceMap, map<string,string> &destMap) {
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




//    //if it's assignment operation
//  else if (arguments[2]=="=") {
//
//    Interpreter *i1 = new Interpreter();
//    insertToMap((*varProgram),i1->GetVariablesMap());
//    var1.SetValue(i1->interpret(arguments[3])->calculate());
//  }
//if there isn't bind