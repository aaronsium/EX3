//
// Created by yaffa on 18/12/2019.
//
#include "General.h"

Print::Print(unordered_map<string, Var> &varProgram)  {
  this->varProgram = &varProgram;
}

int Print:: execute(vector<string> &v){
  string s = v[1];
  //if it's a string
  if(s[0] == '"'){
    cout  << v[1] <<endl;
    //else -> if the variable exist in varProgram->insert it to interpreter's map.
  } else if((*varProgram).find(s) == (*varProgram).end()){
    // not exist -> need to throw exception
  }else{
    Interpreter i;
    insertToMap((*varProgram),i.GetVariablesMap());
//    cout << " rpm + " <<varProgram["rpm"].GetSim()<<endl;
    Expression *e = i.interpret(s);
    cout<<"rpm- " <<e->calculate() << endl;
  }







//    if(commandMap[s]){
//        cout  << commandMap[s] ->value <<endl;
//    }
//    else if(s[0] == '"'){
//        cout  << v[1] <<endl;
//    } else {
//        string delimiter = " ";
//
//        size_t pos = 0;
//        string token;
//        while ((pos = s.find(delimiter)) != std::string::npos) {
//            token = s.substr(0, pos);
//            std::cout << token << std::endl;
//            s.erase(0, pos + delimiter.length());
//        }
//        cout << s << endl;
//    }


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
