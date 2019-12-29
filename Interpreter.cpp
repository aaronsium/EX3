#include <cstring>
#include "General.h"
#include "Expression.h"
#include <stack>
#include <queue>
#include <algorithm>
#include <regex>
using namespace std;

Interpreter::Interpreter() {
  this->precedence["U"] = 3;
  this->precedence["*"] = 2;
  this->precedence["/"] = 2;
  this->precedence["+"] = 1;
  this->precedence["-"] = 1;

}

void Interpreter::setVariables(string exp) {
  char *str = &exp[0];
  // splitting the input variable by variable
  char *token = strtok(str, ";,\000");

  if (!std::regex_match(token, std::regex("[a-zA-Z_]+[a-zA-Z_0-9]*=[0-9\\\\.]+"))) {
    throw "input not valid";
  } else {

    string variable, value;
    while (token!=NULL) {

      string delimiter = "=";
      string convertToken(token);
      variable = convertToken.substr(0, convertToken.find(delimiter));
      value = convertToken.substr(convertToken.find(delimiter) + 1, convertToken.length());

      this->variablesMap[variable] = (value);

      token = strtok(NULL, ";,\000");
//      counter = 0;
    }
  }
}


//[a-zA-Z_]+[a-zA-Z_0-9]*=[0-9\.]+


Expression *Interpreter::interpret(string str) {
  char* inFixExp = &str[0];
  splitInput(inFixExp);
  string convertAll(inFixExp);
  string last = "0";
  // couneter of the vector;
  int counter = 0;
  bool currectOperator = true;
  string topStack;
  if(!operatorStack.empty()) {
    topStack=operatorStack.top();
  }
  for (unsigned int i = 0; i < convertAll.length(); i++) {

    string current(1, inFixExp[i]);
// if its a number/ variable
    if (current!="+" && current!="-" && current!="/" && current!="*" && current!="(" && current!=")"&&currectOperator) {

      currectOperator = false;
      numQueue.push(realNumbers[counter]);
      counter++;
    }


    //אם הוא אופרטור
    if (current=="+" || current=="-" || current=="/" || current=="*") {

      if (last=="+" || last=="-" || last=="/" || last=="*") {
        throw "invalid operator";
      } else {

        currectOperator = true;
        //אם הוא אופרטור
        if (operatorStack.empty()) {
          // אם הוא אונארי
          if (unaryCheck(current, last, i)) {
            if (current=="+") {

            }
            if (current=="-") {
              operatorStack.push("U");
            }
          } else {
            operatorStack.push(current);
          }
        } else if (operatorStack.top()=="(" || operatorStack.top()==")") {
          if (unaryCheck(current, last, i)) {
            if (current=="+") {

            }
            if (current=="-") {
              operatorStack.push("U");
            }
          } else {
            operatorStack.push(current);
          }
        } else if (operatorStack.top()!="(" && operatorStack.top()!=")") {
          // אם הוא בעל קדימות נמוכה יותר
          while (!precedence.empty() && !operatorStack.empty() &&this->precedence[current] < precedence[operatorStack.top()]) {
            topStack = operatorStack.top();
            operatorStack.pop();
            numQueue.push(topStack);
          }
          operatorStack.push(current);
        }

      }
    }
    if (current=="(") {
      if (last==")") {
        throw "invalid input";
      } else
        currectOperator = true;
      operatorStack.push(current);

    }
    if (current==")") {
      topStack = operatorStack.top();
      currectOperator = true;
      while (topStack!="(") {
        operatorStack.pop();
        numQueue.push(topStack);
        topStack = operatorStack.top();
      }
      operatorStack.pop();

    }
    last = current;
  }
  while (!operatorStack.empty()) {
    topStack = this->operatorStack.top();
    operatorStack.pop();
    numQueue.push(topStack);
  }
  return evaluate();
}

void Interpreter::splitInput(string str) {
  char* inFixExp = &str[0];
  char *token = strtok(inFixExp, "+,-,*,/,(,)");
  while (token!=NULL) {
    string convertPart(token);
    realNumbers.push_back(convertPart);
    token = strtok(NULL, "+,-,*,/,(,)");
  }
}

Expression* Interpreter::evaluate() {
  string current = numQueue.front();
//  Expression *temp1;
//  Expression *temp2;
  int queueSize = this->numQueue.size();
  Expression *result;
  string before = numQueue.front();
  string after;
  for (int i = 0; i <queueSize; i++) {
    current = numQueue.front();
    // if it's variable
    if (variablesMap.count(current)) {
      this->finalExp.push(new Variable(current, stod(variablesMap[current]))) ;
    }


    else if (current=="+" || current=="-" || current=="/" || current=="*" || current == "U") {


      if(current == "U"){
        Expression *temp = this->finalExp.top();
        finalExp.pop();
        Expression *temp1 = new UMinus(temp);
        this->finalExp.push(temp1);
//        delete(temp1);

      }

//      if (i==queueSize - 1) {
//        Expression *temp1 = this->finalExp.top();
//        if (current=="+") {
//          temp1 = this->finalExp.top();
//          finalExp.pop();
//          numQueue.pop();
//          this->finalExp.push(new UPlus(temp1));
//        }
//        if (current=="-") {
//          temp1 = this->finalExp.top();
//          finalExp.pop();
//          numQueue.pop();
//          this->finalExp.push(new UMinus(temp1));
//        }
//      }
      else {

        Expression *temp1 = this->finalExp.top();
        finalExp.pop();
        Expression *temp2 = this->finalExp.top();
        finalExp.pop();

        if (current=="+") {
          result = new Plus(temp1, temp2);
        }
        if (current=="-") {
          result = new Minus(temp2, temp1);
        }
        if (current=="*") {
          result = new Mul(temp1, temp2);
        }
        if (current=="/") {
          result = new Div(temp2, temp1);
        }
        if (current=="/") {

        }
        this->finalExp.push(result);
//      delete (result);
      }
    }

      //it's a number
    else{
      bool has_only_digits = (current.find_first_not_of( "0123456789." ) == string::npos);
      if(has_only_digits) {
        this->finalExp.push(new Value(stod(current)));
      } else {
        throw "input not valid";
      }

    }

    before = numQueue.front();
    if(!numQueue.empty()) {
      this->numQueue.pop();
    }
  }
  Expression* final = this->finalExp.top();
  return final;
}

bool Interpreter:: unaryCheck(string opr, string last,int roundNumber ){

  if(opr == "+" || opr == "-"){
    if(last == "(" ){
      return true;
    }
    if(roundNumber==0){
      return true;
    }else {
      return false;
    }
  }else{
    return false;
  }

}
Interpreter::~Interpreter() {

}

