#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
const int N = 1e5;
const int X = 1e6;

typedef long long ll;
ll n, x, y;

int main() {
    cin >> n >> x >> y;
    for (int i=0; i<n; i++) {
        ll h;
        cin >> h;
        h = h - (h / (x + y))*(x+y);
        //cout << h << endl;

        int lastHitter = -1;
        ll ix = y, iy = x;
        ll tx = ix, ty = iy;
        while (h > 0) {
            //cout << "h = " << h << endl;
            //cout << "tx = " << tx << "ty = " << ty << endl;

            if (tx < ty) {
                tx += ix;
                h--;
                lastHitter = 0;
            } else if (ty < tx) {
                ty += iy;
                h--;
                lastHitter = 1;
            } else {
                tx += ix;
                ty += iy;
                h -= 2;
                lastHitter = 2;
            }
            //cout << "lastHitter = " << lastHitter << endl;
        }
        cout << ((lastHitter == 0) ? "Vanya" :
                (lastHitter == 1) ? "Vova" :
                "Both") << endl;
    }
    return 0;
}
