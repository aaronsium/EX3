#include "General.h"

Parser:: Parser(unordered_map<string, Command *> &map1, const vector<string> &vec1,
                unordered_map<string, Var*> &sim1,unordered_map<string, Var> &program1){
  this -> commandMap = map1;
  this -> v = vec1;
  this->varSim = &sim1;
  this->varProgram = &program1;
}

void Parser:: parsing(){
  isParsing = true;
  unsigned int i = 0;
  Command* c = NULL;
  //activate all commands in the lexer
  while(i < v.size()){
    while(v[i] == "}"){
      if(loop) {
        i=i-stepsLoop;
        loop=false;
      }else {
        i++;
      }
    }
    if(v[i] == "var"){
      if(commandMap.find(v[i+1]) == commandMap.end()){
        commandMap[v[i+1]] = new SetVarCommand(*varSim, *varProgram);
      }
    }
    c = commandMap[v[i]];
    if(c != NULL){
      vector<string> vec = cut(i);
      i += c->execute(vec);
    }
  }
}
vector<string> Parser:: cut( int m){
    auto first = v.cbegin() + m;
    auto last = v.cend();

    vector<string> vec(first, last);
    return vec;
}

