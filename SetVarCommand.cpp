//
// Created by aharon on 21/12/2019.
//

#include "General.h"
SetVarCommand::SetVarCommand(string name,
                             double value,
                             unordered_map<string, Var> varSim,
                             unordered_map<string, Var> varProgram,
                             int sockfd) {
  this->sockfd = sockfd;
  this->name = name;
  this->value = value;
  this->varProgram = varProgram;
  this->varSim = varSim;
}

int SetVarCommand::execute(vector<string> &arguments) {
  Var *var1 = &(this->varProgram[arguments[0]]);
  var1->SetValue(this->value);
  //if var 1 is bound to varSim -> update the sim variable by sending a message
  if (var1->GetBoundWay()=="->") {
    return sendMessage(var1->GetSim());
  }

}
//
ssize_t SetVarCommand::sendMessage(string path) {

  string message = "set " + path + " " + to_string(this->value) + "\r\n";
  ssize_t return_val;
  return_val = write(sockfd, message.c_str(), message.length());

}