#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define s(n) scanf("%ld", &n)
#define pr(n) printf("%ld ", n)
#define prln() printf("\n")

//only works if there's exactly 1 space/newline after the number

int main() {
    long n1, n2, t, l, i, k, ans;
    char ch;
    char s1[10001], s2[10001];
    char* ss2;
    s(t);
    while (t--) {
        scanf("%s", s1);
        scanf("%s", s2);
        n1 = strlen(s1);
        n2 = strlen(s2);
        s(l);
        for (k=1; k<=l; k++) {
            ans = 0;
            for (i=0; i<=n1-k; i++) {
                ss2 = s2;
                while (ss2 != NULL && ss2 - s2 <= n2-k) {
                    //cut the string s1 out,
                    ch = s1[i+k];
                    s1[i+k] = '\0';
                    //use it to find the s2s
                    ss2 = strstr(ss2, s1+i);
                    s1[i+k] = ch;
                    if (ss2 != NULL) {
                        ans++;
                        ss2++;
                    } else {
                        break;
                    }

            //printf("AAHUT%ld\n", i);
            //printf("%c", *ss2);
                }
            }
            pr(ans);
            //prln();
        }
        prln();
    }
    return 0;
}
