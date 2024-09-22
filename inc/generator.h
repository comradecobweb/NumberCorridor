#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H


#ifdef __cplusplus
extern "C" {
#endif


#include <stdlib.h>
#include <time.h>


    //void generate_pi(int * array, const int length);
    void generate_decimal(int * array, const int length, const int max);


#ifdef __cplusplus
}
#endif


#endif //GENERATOR_H