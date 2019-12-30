//
// Created by yaffa on 28/12/2019.
//

#include "General.h"

int ifCommand:: execute(vector<string> &v){
    int scopeSize = commandsCounter(v);

    if(checkCondition(v)){
        return 5;
    }
    return scopeSize;
};

vector<string> ifCommand:: cut(vector<string> &v, int m){
    auto first = v.cbegin();
    auto last = v.cbegin() + m;

    vector<string> vec(first, last);

    return vec;
}