//
// Created by aharon on 18/12/2019.
//

#include <fstream>
#include "General.h"
#include <algorithm>
#include <cstring>
#include <sstream>
Lexer::Lexer(string fileName1) {
  this->fileName = fileName1;
}
void Lexer::lexing() {
  fstream newFile;
  newFile.open(fileName, ios::in); //open a file to perform read operation using file object
  if (newFile.is_open()) {   //checking whether the file is open
    string line;
    while (getline(newFile, line)) { //read data from file object and put it into string.
      fixLine(line);
    }
    newFile.close(); //close the file object.
  }
  //printing all vector elements
//  for (int i = 0; i < v1.size(); i++) {
//    cout << v1[i] + "\n";
//  }
}
void Lexer::fixLine(string &line) {
  line.erase(std::remove(line.begin(), line.end(), '\t'), line.end());
  // convert string to char*
  char *newLine = new char[line.length() + 1];
  std::strcpy(newLine, line.c_str());
  // splitting the tokens
  string s1 = "while";
  string s2 = "if";
  string s3 = "var";
  if (line.find('=') != std::string::npos && !(isprefix(line, s1) || isprefix(line, s2) ||
  isprefix(line, s3))&&(!(line.find('"') != std::string::npos))){
    char *token = strtok(newLine, "=");
    bool firstLoop= true;
    while (token!=NULL) {
      string str(token);
      str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
      this->v1.push_back(str);
      if(firstLoop){
        this->v1.push_back("=");
      }
      token = strtok(NULL, "=");
      firstLoop = false;
    }
  }else{

      char *token = strtok(newLine, ",()");
      while (token!=NULL) {
        string str(token);
        removeWhite(str);
        token = strtok(NULL, ",()");
      }
    }
  delete[] newLine;
}

void Lexer::removeWhite(string line) {
  if (line[0]!='"') {
    string s1 = "while";
    string s2 = "if";
    if (isprefix(line, s1) || isprefix(line, s2)) {
      string variable = "";
      string value = "";
      string operat = "";
      string condition = "";

      int counter = 0;
      while (line[counter]!=' ') {
        condition = condition + line[counter];
        counter++;
      }
      while (line[counter]!='>' && line[counter]!='<' && line[counter]!='=') {
        if (line[counter]!=' ') {
          variable = variable + line[counter];
        }
        counter++;
      }
      while (line[counter]==' ') {
        counter++;
      }
      while (line[counter]=='>' || line[counter]=='<' || line[counter]=='=') {
        while(line[counter]!=' ') {
          operat = operat + line[counter];
          counter++;
        }
      }

      while (line[counter]!='{') {
        if (line[counter]!=' ') {
          value = value + line[counter];
        }
        counter++;
      }
      this->v1.push_back(condition);
      this->v1.push_back(variable);
      this->v1.push_back(operat);
      this->v1.push_back(value);
      this->v1.push_back("{");
    } else {

      vector<string> strings;
      istringstream f(line);
      string s;
      while (getline(f, s, ' ')) {
        if(s!=""){
          this->v1.push_back(s);
        }
      }
    }

  }else {
    this->v1.push_back(line);
  }
}
const vector<string> &Lexer::GetV1() const {
  return v1;
}

bool Lexer::isprefix(string &str, string &prefix) {
  if (str.length() < prefix.length()) {
    return false;
  } else {
    bool isPrefix = prefix.size() <= str.size() &&
        std::mismatch(prefix.begin(), prefix.end(),
                      str.begin(), str.end()).first==prefix.end();
    if (isPrefix) {
      return true;
    } else {
      return false;
    }
  }

}
Lexer::~Lexer() {

}

