//
// Created by yaffa on 28/12/2019.
//

#include "General.h"

int ifCommand:: execute(vector<string> &v){
    int scopeSize = commandsCounter(v);

    if(checkCondition(v)){
        //need to use global map
        Parser par = new Parser (map<string, Command*> map, cut(v, scopeSize));
        //activate the commands in the scope
        par.parsing();
    }

    return scopeSize;
};

vector<string> ifCommand:: cut(vector<string> &v, int m){
    auto first = v.cbegin();
    auto last = v.cbegin() + m;

    vector<string> vec(first, last);
    return vec;
}