//
// Created by aharon on 21/12/2019.
//

#include "General.h"
SetVarCommand::SetVarCommand(unordered_map<string, Var> &varSim,unordered_map<string, Var> &varProgram){
  this->varSim = &varSim;
  this->varProgram = &varProgram;
}

int SetVarCommand::execute(vector<string> &arguments) {
  Interpreter* i2 = new Interpreter();
  Var *var1 = &((*varProgram)[arguments[0]]);
  var1->SetValue(i2->interpret(arguments[2])->calculate());
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