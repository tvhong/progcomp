/*
ID: shiweis1
LANG: C++
PROB: crypt1
*/
#include <cstdio>

#define s(x) fscanf(fin, "%d", &x)
using namespace std;

int check(int n, int* h) {
    if (n >= 1000) {
        return (h[n/1000] && h[(n/100)%10] && h[(n/10)%10] && h[n%10]);
    } else if (n >=100) {
        return (h[n/100] && h[(n/10)%10] && h[n%10]);
    }
}

int main() {
    int n, i, i1, i2, i3, i4, i5;
    int a[10], h[10] = {0};
    FILE * fin = fopen("crypt1.in", "r");
    FILE * fout = fopen("crypt1.out", "w");
    s(n);
    for (i=0; i<n; i++) {
        s(a[i]);
        h[a[i]] = 1;
    }

    int ans = 0;

    for (i1=0; i1<n; i1++)
        for (i2=0; i2<n; i2++)
            for (i3=0; i3<n; i3++)
                for (i4=0; i4<n; i4++)
                    for (i5=0; i5<n; i5++) {
                        int num1 = 100*a[i1] + 10*a[i2] + a[i3];
                        int p1 = a[i5]*num1;
                        int p2 = a[i4]*num1;
                        int sum = p1 + 10*p2;
                        if (p1 < 111 || p1 > 999 || p2 < 111 || p2 > 999 ||
                                sum < 1111 || sum > 9999)
                            continue;
                        if (check(p1, h) && check(p2, h) && check(sum, h))
                            ans++;
                    }
    fprintf(fout, "%d\n", ans);

    return 0;
}
