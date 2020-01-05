//
// Created by aharon on 21/12/2019.
//

#include "General.h"
SetVarCommand::SetVarCommand(unordered_map<string, Var*> &varSim,unordered_map<string, Var> &varProgram){
  this->varSim = &varSim;
  this->varProgram = &varProgram;
}

int SetVarCommand::execute(vector<string> &arguments) {


  Interpreter i2;
  Var *var1 = &((*varProgram)[arguments[0]]);
  insertToMap((*varProgram),i2.GetVariablesMap());
  Expression *x = i2.interpret(arguments[2]);
  var1->SetValue(x->calculate());
  //if var 1 is bound to varSim -> update the sim variable by sending a message
  if (var1->GetBoundWay()=="->") {
    setQueue.push(*var1);
  }
  return 3;
}
//
ssize_t SetVarCommand::sendMessage(string path) {

  string message = "set " + path + " " + to_string(this->value) + "\r\n";
  ssize_t return_val;
  return_val = write(sockfd, message.c_str(), message.length());

}

void SetVarCommand::insertToMap(unordered_map<string, Var> &sourceMap, map<string,string> &destMap) {
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