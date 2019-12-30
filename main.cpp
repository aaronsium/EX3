#include "General.h"
using namespace std;

#define PORT 8081
int main() {
  // reading from the file-> splitting to commands-> inserting them to an vector
  Lexer lex("fly.txt");
  lex.lexing();
  // creating maps of variables and defineVarCommand
  unordered_map<string,Variable> varSim;
  unordered_map<string,Variable> varProgram;
  defineVarCommand VarCommand (varSim, varProgram);

  // complete ‫‪parser‬(remember to insert VarCommand which created above, to the parser‬//





////  ConnectCommand connect;
//  vector<string> v2;
//  v2.push_back("connectControlClient");
//  v2.push_back("127.0.0.1");
//  v2.push_back("5402");
////  connect.execute(v2);



  return 0;
}



