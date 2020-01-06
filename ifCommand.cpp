//
// Created by yaffa on 28/12/2019.
//

#include "General.h"

ifCommand::ifCommand(unordered_map<string, Var*> &var_sim,
                     unordered_map<string, Var> &var_program) : ConditionParser(var_sim, var_program) {

}

int ifCommand:: execute(vector<string> &v){
    int scopeSize = commandsCounter(v);
    // if condition is true continue as usual
    if(checkCondition(v)){
        return 5;
    }
    // else  skip over scope
    return scopeSize;
}

ifCommand::~ifCommand() {

}
