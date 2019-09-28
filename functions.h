#include <string.h>

// Sequence Length
int seqLen(char *seq){
    int length = strlen(seq);
    return length;
}

// Affine gap penalty
int aff(const int d, int n, const int e){
    int g;
    g = d + (n-1)*e;
    return g;
}

// Linear gap penalty
int linear(const int g, int l){
    int lin;
    lin = g*l;
    return lin;
}

// Maximum score calculation
int max(int x, int y, int z){
    int max;
    if (x >= y && x >= z){
        max = x;
    }
    else if (y >= x && y >= z){
        max = y;
    }
    else{
        max = z;
    }
    return max;
}
