//
// Created by yaffa on 18/12/2019.
//

#include "General.h"

int Sleep:: execute(vector<string> &v){
    Interpreter i;
    Expression *e = i.interpret(v[1]);
//    sleep(e->calculate());
  int seconds = (int)round(e->calculate());
  this_thread::sleep_for(chrono::milliseconds(seconds));
    return 2;
}

void Sleep:: sleep(int milli) {




    clock_t end_time;
    end_time = clock() + milli * CLOCKS_PER_SEC/1000;
    while (clock() < end_time) {
        //blank loop for waiting
    }
}