#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "align.h"

int main(int argc, char *argv[]){
    // Sequences
    char *ref = argv[1];
    char *query = argv[2];
    
    // Match, Mismatch, and Gap scores
    int m = atoi(argv[3]);
    int ms = atoi(argv[4]);
    int g = atoi(argv[5]);
    
    align(ref, query, m, ms, g);
}


