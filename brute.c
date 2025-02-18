#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib.h"
#define bool _Bool

// bad lol
double randd(void){
    double r = rand();
    r = (r + sin(r));
    return r;
}

double dol(double x, double input){
    double expr = (fpow(x, 5) + x + x * 10 - (input));
    return expr;
}

int main(int argc, char* argv[]){
    double input;
    int num_gens = 50000;
    bool debug = 0;
    if (argc > 1){ 
        if (argc > 3){
            printf("invalid amt of args\n");
            return -1;
        }
        else{
            input = atof(argv[1]);
            if (!input){
                printf("USAGE: '%s numGoal -flags'\n", argv[0]); 
                return -1;
            }
            if (argc > 2){
                if (!memcmp(argv[2], "--debug", 7)){
                    debug = 1;
                }
            }
        }       
    }       
    else{
        printf("USAGE: '%s numGoal -flags'\n", argv[0]);
        return -1;
    }
    srand(time(NULL));
    double x, tmp;
    int i, j;
    x = randd();
    for (i = 0; i < num_gens; ++i){
        tmp = fmod(randd(), x);
        if (dol(tmp, input) < dol(x, input)){
            if (dol(tmp, input) > 0){
                x = tmp;
            }
        }
        if (debug && !((i + 1) % 50)){
            printf("generation %d: x = %.5f\n", i+1, x);
        }
    }
    printf("final generation: x = %.5f\n", x);
    return 0;
}
