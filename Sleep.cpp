//
// Created by yaffa on 18/12/2019.
//

#include "General.h"

int Sleep:: execute(vector<string> &v){
    Interpreter i;
    Expression *e = i.interpret(v[1]);
  int seconds = (int)round(e->calculate());
  this_thread::sleep_for(chrono::milliseconds(seconds));
    return 2;
}

Sleep::~Sleep() {

}
