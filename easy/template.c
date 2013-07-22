#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define pr(n) printf("%d ", n)
#define prln() printf("\n")

//only works if there's exactly 1 space/newline after the number
int s() {
    int inp=0;
    char c=getchar_unlocked();
    while (c>='0'&&c<='9') {
        inp = inp*10+c-'0';
        c=getchar_unlocked();
    }
    return inp;
}

int main() {
    return 0;
}
