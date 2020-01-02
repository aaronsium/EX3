#include "General.h"

Parser:: Parser(unordered_map<string, Command *> &map, const vector<string> &vec){
    this -> commandMap = map;
    this -> v = vec;
}

void Parser:: parsing(){
   isParsing = true;
    int i = 0;
    Command* c = NULL;
    //activate all commands in the lexer
    while(i < v.size()){
        while(v[i] == "}"){}
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

