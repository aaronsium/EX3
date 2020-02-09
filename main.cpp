#include "General.h"
using namespace std;

bool isParsing = false;
bool isServerOpen= false;
bool serverReady = false;
queue<Var> setQueue ;
bool loop = false;
int stepsLoop = 0;
vector<string> loopLex;
condition_variable isThreadEnd;
condition_variable isThreadEnd2;
std::mutex mutex1;
std::mutex mutex2;

void resetCommandMap(unordered_map<string,Var*> &varSim,
                     unordered_map<string,Var> &varProgram, unordered_map<string, Command*> &commandMap){
  commandMap["openDataServer"] = new OpenServer(varSim);
  commandMap["connectControlClient"] = new ConnectCommand;
  commandMap["var"] = new DefineVarCommand(varSim, varProgram);
  commandMap["Print"] = new Print(varProgram);
  commandMap["Sleep"] = new Sleep;
  commandMap["if"] = new ifCommand(varSim, varProgram);
  commandMap["while"] = new loopCommands(varSim, varProgram);
}

int main(int arg, char *args[]) {
  if(args[0] == 0){
    cout<<"error: file name was not provided"<<endl;
    exit(0);
  }
  string fileName(args[1]);
  // reading from the file-> splitting to commands-> inserting them to an vector
  Lexer lex(fileName);
  lex.lexing();
  // creating maps of variables and defineVarCommand
  unordered_map<string,Var*> varSim;
  unordered_map<string,Var> varProgram;
  // creating maps of command pointers and insert it
  unordered_map<string, Command*> commandMap;
  resetCommandMap(varSim, varProgram, commandMap);
  Parser par(commandMap, lex.GetV1(), varSim, varProgram);
  //going through all command in lexer array
  par.parsing();
  isParsing = false;
  unique_lock<std::mutex> lock1(mutex1);
  unique_lock<std::mutex> lock2(mutex2);
  isThreadEnd.wait(lock1);
  isThreadEnd2.wait(lock2);
  return 0;
}


