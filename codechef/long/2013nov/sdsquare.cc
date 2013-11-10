#include <cstdio>
#include <cmath>

#define s(x) scanf("%lld", &x)
#define PRIME 1000000007
#define SIZE 510
#define MAX 10000000000
typedef long long LL;

using namespace std;

LL t;
LL a[SIZE], b[SIZE], ans[SIZE];
LL ps[4] = {0, 1, 4, 9};
void re(LL i, LL num) {
    if (i == 10) {
        LL tmp = sqrt(num*1.0);
        if (tmp*tmp == num)
           for (int j=0; j<t; j++)
              if (num >= a[j] && num <= b[j])
                ans[j]++; 
        return;
    }
    for (int j=0; j<4; j++)
        re(i+1, num*10+ps[j]);
}

int main() {
    s(t);
    LL i;
    for (i=0; i<t; i++) {
        s(a[i]);
        s(b[i]);
    }
    re(0, 0);
    for (i=0; i<t; i++) {
        if (b[i] == MAX) ans[i]++;
        printf("%lld\n", ans[i]);
    }
    return 0;
}
