//
// Created by yaffa on 18/12/2019.
//
#include "General.h"

Print::Print(unordered_map<string, Var> &varProgram1)  {
  this->varProgram = &varProgram1;
}

int Print:: execute(vector<string> &v){
    string s = v[1];
    //if it's a string
    if(s[0] == '"'){
        int i = 1;
        char end = s[s.length() - 1];
        //
        while (end != '"'){
            i++;
            s += " " + v[i];
            end = s[s.length() - 1];
        }
        cout << s << endl;
        return i + 1;

        //else -> if the variable exist in varProgram->insert it to interpreter's map.
    } else {
        if ((*varProgram).find(s) == (*varProgram).end()) {
            // not exist -> need to throw exception
        } else {
            Interpreter i;
            insertToMap((*varProgram), i.GetVariablesMap());
            Expression *e = i.interpret(s);
            cout<< e->calculate() << endl;
        }
    }

  return 2;
}

void Print::insertToMap(unordered_map<string, Var> &sourceMap, map<string,string> &destMap) {
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
Print::~Print() {

}
