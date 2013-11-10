/*
ID: shiweis1
LANG: C++
PROG: calfflac
*/
#include <cstdio>
#include <cctype>

#define SIZE 20000
using namespace std;

int isPalindrome(char* s, int i, int j) {
    while (i < j && s[i] == s[j]) {
        i++;
        j--;
    }
    //printf("i=%d, j=%d\n", i, j);
    return (i >= j);
}

int main() {
    FILE * fin = fopen("calfflac.in", "r");
    FILE * fout = fopen("calfflac.out", "w");
    char text[SIZE], str[SIZE];
    int ind[SIZE];
    char ch;
    int n=0, m = 0;

    while (ch=fgetc(fin),ch != EOF) {
        if (isalpha(ch)) {
            str[m] = tolower(ch);
            ind[m++] = n;
        }
        text[n++] = ch;
    }

    //printf("m=%d,str=|%s|\n", m, str);
    int i, j, s=0, t=0;
    for (i = 0; i<m; i++) {
        for (j = 1999; j>=0; j--) {
            if (i+j >= m) continue;
            //printf("%d %d\n", i, j);
            if (j <= (t-s)) break;
            if (isPalindrome(str, i, i+j)) {
                s = i;
                t = i + j;
            }
        }
    }

    text[ind[t]+1] = '\0';

    fprintf(fout, "%d\n", t-s+1);
    //printf("%d %d, %d %d\n", s, t, ind[s], ind[t]);
    fprintf(fout, "%s\n", text+ind[s]);

    return 0;
}
