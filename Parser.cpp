#include "General.h"

Parser:: Parser(map<string, Command*> map, vector<string> &vec){
    this->myMap = map;
    this->v = vec;
}

void Parser:: parsing(){
    int i = 0;
    Command* c = NULL;
    //activate all commands in the lexer
    while(i < v.size()){
        while(v[i] == "}"){
            i++;
        }
        c = myMap[v[i]];
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

