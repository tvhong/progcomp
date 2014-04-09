#include <stdio.h>
#include <stdlib.h>
#define s(n) scanf("%d", &n)
#define pr(n) printf("%d", n)
#define prln() printf("\n")
#define MAX(n,m) n>m?n:m
#define MIN(n,m) n<m?n:m

int fastinput() {
    int inp=0;
    char c=getchar_unlocked();
    while (c>='0'&&c<='9') {
        inp = inp*10+c-'0';
        c=getchar_unlocked();
    }
    return inp;
}

int t,n,i,s,e,tmp;

int main() {
    t = fastinput();
    while(t--){
        n = fastinput();
        int val[49]={0}, c[49][49]={{0}};
        for (i=0;i<n;i++) {
            s = fastinput();
            e = fastinput();
            tmp = fastinput();
            if (tmp > c[s][e]) c[s][e] = tmp;
        }
        for (e=1;e<=48;e++) {
            for (s=0;s<e;s++) {
                val[e] = MAX(val[e], val[s]+c[s][e]);
            }
        }
        /*
        for (e=0;e<=48;e++) {
            pr(val[e]);
            prln();
        }
        */
        printf("%d\n", val[48]);
    }
    return 0;
}
