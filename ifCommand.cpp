//
// Created by yaffa on 28/12/2019.
//

#include "General.h"

ifCommand::ifCommand(unordered_map<string, Var*> &var_sim,
                     unordered_map<string, Var> &var_program) : ConditionParser(var_sim, var_program) {

}

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