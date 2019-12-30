//
// Created by yaffa on 19/12/2019.
//

#ifndef PROJECT3_COMMAND_H
#define PROJECT3_COMMAND_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;
/**
 * Command Interface
 */

class Command {

public:
    virtual int execute(vector<string> &v) = 0;
    virtual ~Command() {}
};

#endif //PROJECT3_COMMAND_H