//
// Created by new on 2018/2/1.
//



#include "defns.i"
#include "extern.i"


int FloatEqual(float num1, float num2){
    if(num1 - num2 > -0.0000001 && num1 - num2 < 0.0000001)
        return 1;
    return 0;
}