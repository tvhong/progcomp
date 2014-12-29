#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int N = 1e5;
const int X = 1e6;
const double EPS = 1e-8;
const double EPS_ANS = 1e-6;

typedef unsigned long long ull;
ull n, x, y;

bool zero(double x) {
    return fabs(x) < EPS;
}

int main() {
    cin >> n >> x >> y;
    for (int i=0; i<n; i++) {
        ull h;
        cin >> h;
        h = h - (h / (x + y))*(x+y);
        //cout << h << endl;

        if (h == 0) {
            cout << "Both" << endl;
            return 0;
        }

        ull ix = y, iy = x;
        double tx = ix, ty = iy;
        double hi = (double)x*y, lo = 0;
        for (int i=0; i<40; i++) {
            //cout << endl << "i = " << i << ", h = " << h << ", lo = " << lo <<
                //", hi = " << hi+lo << endl;
            double m = hi / 2.0;

            // Check if at time m the monster is dead
            ull xhits = (m-tx >= -EPS) ? (ull)((m-tx) / ix) + (zero(tx) ? 0 : 1) : 0;
            ull yhits = (m-ty >= -EPS) ? (ull)((m-ty) / iy) + (zero(ty) ? 0 : 1) : 0;
            //cout << "m = " << m+lo << ", dis = " << m << ", xhits = " << xhits << ", yhits = " << yhits << endl;
            //cout << "tx = " << tx << ", ty = " << ty << endl;
            if (xhits + yhits < h) {
                h -= xhits + yhits;

                if (m >= tx) {
                    int nintervals = ((m - tx) / ix);
                    tx = ix - ((m - tx) - nintervals * ix);
                } else {
                    tx = tx - m;
                }

                if (m >= ty) {
                    int nintervals = ((m - ty) / iy);
                    ty = iy - ((m - ty) - nintervals * iy);
                } else {
                    ty -= m;
                }
                
                lo += m;
            }
            hi = m;
        }
        bool xlast = (fabs(tx) <= EPS_ANS);
        bool ylast = (fabs(ty) <= EPS_ANS);

        cout << ((xlast && ylast) ? "Both" :
                (xlast) ? "Vanya" :
                "Vova") << endl;
    }
    return 0;
}
