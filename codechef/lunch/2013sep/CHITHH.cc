/*
 * Problem: Chef and Science
 */
#include <bits/stdc++.h>
using namespace std;

#define mk make_pair
#define pb push_back
#define x first
#define y second

#define SIZE 100010
#define MAX_LENGTH 10
#define s(x) scanf("%d", &x)
typedef long long ll;

char a[SIZE][MAX_LENGTH];
int len[SIZE];
int n, m, i, j, l, v, k, ans;

int trivia(int l, int v, int k, int n) {
    int i = l-1;
    k--;
    while (i<n && k>=len[i]) {
        k -= len[i];
        i += v;
    }
    //printf("k=%d\n", k);
    return (i < n) ? a[i][k] : -1;
}

int getRealI(int i) {
    return i*v + l%v;
}

int sqrtm;
void pre() {
    sqrtm = ceil(sqrt(SIZE));
    int i, v;
    for (v=0; v<sqrtm; v++) {
        for (i=0; i<v; i++) {
            sLen[i] = 
        }
    }
}
int upB(int* a, int n, int key) {
    int lo=-1, hi=n;
    while (lo < hi-1) {
        int mid = (lo+hi)/2;
        if (key < a[getRealI(mid)]) hi = mid;
        else lo = mid;
    }
    return hi;
}

int main() {
    s(n);
    char ch = getchar();
    for (i=0; i<n; i++) {
        while (ch < '0' || ch >'9') ch = getchar();
        j = 0;
        while (ch >= '0' && ch <= '9') {
            a[i][j++]=ch;
            ch = getchar();
        }
        len[i] = j;
    }
    s(m);
    while (m--) {
        s(l); s(v); s(k);
        //ans = naiev(a, l, v, k, n, len);
        ans = trivia(l, v, k, n);
        if (ans == -1) printf("So sad\n");
        else printf("%c\n", ans);
    }
    /*
    for (i=0; i<n; i++) {
        printf("a[%d] = %s, l=%d\n", i, a[i],len[i]);
    }
    */
    return 0;
}
