//
// Created by yaffa on 18/12/2019.
//

#include "General.h"

int Print:: execute(vector<string> &v){
    string s = v[1];
    if(s[0] == '"'){
        cout  << v[1] <<endl;
    } else {
        Interpreter i;
        Expression *e = i.interpret(s);
        cout<< e->calculate() << endl;
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

