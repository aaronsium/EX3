//
// Created by aharon on 18/12/2019.
//
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <bits/stdc++.h>
#include <arpa/inet.h>
#include <fstream>
#include <algorithm>
#include <cstring>
#include <Command.h>

using namespace std;
using namespace std::literals::chrono_literals;

struct node {
    float value;
    string sim;
};

class Lexer {
 private:
  string fileName;
  vector<string> v1;
 public:
  Lexer(string fileName);
  void lexing();
  void fixLine(string &line);
  void removeWhite(string line);
  const vector<string> &GetV1() const;
  bool isprefix(string &str, string &prefix);

};

class Variable {
 private:
  double value;
  string BoundWay = "-1";
  string sim;
 public:
  void SetValue(double value);
  void SetBoundWay(const string &bound_way);
  void SetSim(const string &sim);
  double GetValue() const;
  const string &GetBoundWay() const;
  const string &GetSim() const;
 public:
  Variable();

};

class defineVarCommand : public Command {
 private:
  unordered_map<string, Variable> varSim;
  unordered_map<string, Variable> varProgram;
 public:
  defineVarCommand(unordered_map<string, Variable> varSim,
                   unordered_map<string, Variable> varProgram
                   );
  int execute(vector<string> &arguments);
};

class SetVarCommand : public Command {
 private:
  int sockfd;
  unordered_map<string, Variable> varSim;
  unordered_map<string, Variable> varProgram;
  string name;
  double value;
 public:
  SetVarCommand(string name,
                double value,
                unordered_map<string, Variable> varSim,
                unordered_map<string, Variable> varProgram, int sockfd);
  int execute(vector<string> &arguments);
  ssize_t sendMessage(string path);
};

class ConnectCommand : public Command {

 public:
  ConnectCommand();
  int clientConnect(int PORT, const char *hostAdress);
  int execute(vector<string> &arguments);
};

class ConditionParser : public Command {
 protected:
  bool condition = false;
 public:
  ConditionParser();
  int execute(vector<string> &arguments) override;
  int commandsCounter(vector<string> &arguments);
  bool checkCondition (vector<string> &arguments);
};

class loopCommands : public ConditionParser {

 public:
  loopCommands();
  int execute(vector<string> &arguments);
};

class Expression {

 public:
  virtual double calculate() = 0;
  virtual ~Expression() {}
};

class Interpreter {
 private:
  string inPutString;
  map<string,string > variablesMap;
  map<string,int> precedence;
  stack<string>operatorStack;
  stack<Expression*>finalExp;
  queue<string>numQueue;
  string postFixExp;
  vector< string> realNumbers;

 public:
  Interpreter ();
  Expression* evaluate ();
  Expression* interpret(string str);
  void setVariables(string exp);
  void splitInput(string str);
  bool unaryCheck(string opr, string last,int roundNumber );
  virtual ~Interpreter();

};

class ifCommand: public ConditionParser {
public:
    int execute(vector<string> &v) override;
    vector<string> cut(vector<string> &v, int m);
};

class OpenServer: public Command{
protected:
    unordered_map<string,Variable> pathMap;
    OpenServer(unordered_map<string,Variable> &varProgram);
    string ip = "";
    int port;
    int socke;
    string table[36];

public:
    int execute(vector<string> &v) override;
    void Server();
    void tableUpdate();
};

class Print: public Command {
private:
    map<string, node*> commandMap;
public:
    int execute(vector<string> &v) override;

};

class Sleep: public Command{
public:
    int execute(vector<string> &v) override;
    void sleep(int milli);
};

class Parser {
private:
    map<string, Command*> myMap;
    vector<string> v;
public:
    Parser(map<string, Command*> map, vector<string> &vec);
    void parsing();
    vector<string> cut(int m);
};
