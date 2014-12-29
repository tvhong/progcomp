#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1e5;
const int X = 1e6;

typedef long long ll;
ll n, x, y;
vector<string> rez;

int main() {
    cin >> n >> x >> y;
    ll ix = y, iy = x;
    ll xx = ix, yy = iy;
    while (xx <= x*y || yy <= x*y) {
        if (xx < yy) {
            rez.push_back("Vanya");
            xx += ix;
        } else if (yy < xx) {
            rez.push_back("Vova");
            yy += iy;
        } else {
            rez.push_back("Both");
            rez.push_back("Both");
            xx += ix;
            yy += iy;
        }
    }

    for (int i=0; i<n; i++) {
        ll h;
        cin >> h;
        h = h - (h / (x + y))*(x+y);
        if (h == 0) {
            cout << "Both" << endl;
            continue;
        }
        cout << rez[h-1] << endl;
    }
    return 0;
}
