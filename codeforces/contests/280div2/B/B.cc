#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 1005;
const double E = 1e-9;
int n, l;
int a[N];
double toFront, toBack;

bool isBad(double d) {
    if (d < toFront || d < toBack) return true;

    bool bad = false;
    for (int i=0; i<n-1; i++) {
        if (double(a[i+1] - a[i]) > 2.0*d) {
            bad = true;
            break;
        }
    }
    return bad;
}

int main() {
    toFront = toBack = 1e9+5;
    scanf("%d %d", &n, &l);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        toFront = min(toFront, (double)a[i]);
        toBack = min(toBack, (double)l - a[i]);
    }
    sort(a, a+n);
    //for (int i = 0; i<n; i++) {
    //    printf("a[%d] = %d\n", i, a[i]);
    //}

    double hi = l, lo = 0;
    for (int i=0; i<70; i++) {
        //printf("hi = %.10f, lo = %.10f\n", hi, lo);
        double m = (hi + lo) / 2.0;
        if (isBad(m)) {
            lo = m;
        } else {
            hi = m;
        }
    }
    printf("%.9f\n", hi);

    return 0;
}
