/*
ID: shiweis1
LANG: C++
PROG: crypt1
*/
#include <cstdio>
#include <cstdlib>

#define SIZE 10
#define BSIZE 5
using namespace std;

int ans;
int checkDigits(int num, int n, int* h) {
    while (num > 0) {
        if (!h[num % 10])
            return false;
        num /= 10;
    }
    return true;
}

int blah;
void cal(int n, int* b, int* h) {
    int num1=0, num2=0;
    for (int j=0; j<3; j++) {
        num1 *= 10;
        num1 += b[j];
    }
    for (int j=0; j<2; j++) {
        num2 *= 10;
        num2 += b[BSIZE-j-1];
    }
    //printf("%d %d\n", num1, num2);
    int part1 = num1 * b[BSIZE-1];
    int part2 = num1 * b[BSIZE-2];
    int res = num1 * num2;
    if (part1 < 1000 && part2 < 1000 && res < 10000 &&
            part1 > 99 && part2 > 99 && res > 999 && 
            checkDigits(part1, n, h) && checkDigits(part2, n, h)
            && checkDigits(res, n, h)) 
        ans++;
}

int main() {
    int n, i, j, k, h, l;
    int ha[10] = {0};
    int a[10];
    int b[BSIZE];
    FILE* fin = fopen("crypt1.in", "r");
    FILE* fout = fopen("crypt1.out", "w");
    fscanf(fin, "%d", &n);
    for (i=0; i<n; i++) {
        fscanf(fin, "%d", &a[i]);
        ha[a[i]] = 1;
    }

    //run(0, n, a, b);
    for (i=0; i<n; i++)
        for (j=0; j<n; j++)
            for (k=0; k<n; k++)
                for (h=0; h<n; h++)
                    for (l=0; l<n; l++) {
                        b[0] = a[i];
                        b[1] = a[j];
                        b[2] = a[k];
                        b[3] = a[h];
                        b[4] = a[l];
                        cal(n, b, ha);
                    }
    fprintf(fout, "%d\n", ans);

    return 0;
}
