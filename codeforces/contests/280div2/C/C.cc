#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

#define x first
#define y second

using namespace std;

const int N = 1e5 + 5;
const double E = 1e-8;

int n, r, avg;
long long totcost;
pair<int, int> a[N];

int main() {
    scanf("%d %d %d", &n, &r, &avg);
    double cur_avg = 0;
    for (int i=0; i<n; i++) {
        //y = point, x = cost
        scanf("%d %d", &a[i].y, &a[i].x);
        cur_avg += a[i].y;
    }
    cur_avg /= n;
    if (cur_avg > avg) {
        printf("0\n");
        return 0;
    }
//    for (int i=0; i<n; i++) {
//        printf("a.x = %d, a.y = %d\n", a[i].x, a[i].y);
//    }
    double tmp = ((double)avg - cur_avg) * n;
    long long needed = (long long)tmp;
    if (tmp - (double)needed > E) {
        needed++;
    }

    sort(a, a+n);

    totcost = 0;
    for (int i=0; i<n && needed > 0; i++) {
        if (a[i].y >= r) continue;
        long long gain = r - a[i].y;
        if (needed - gain < 0) {
            totcost += needed*a[i].x;
            break;
        }
        needed -= gain;
        totcost += gain*a[i].x;
    }
    cout << totcost << endl;

    return 0;
}
