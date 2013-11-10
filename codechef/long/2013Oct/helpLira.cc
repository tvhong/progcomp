#include <bits/stdc++.h>

using namespace std;

#define F_MAX 1e9f
#define F_MIN -1e9f
int main() {
    int N, i, x1, y1, x2, y2, x3, y3;
    double mina = F_MAX, maxa = F_MIN;
    int mini = 0, maxi = 0;
    cin >> N;
    for(i=1; i<=N; i++) {
        cin >> x1 >> y1 >> x2 >> y2 >> x3>>y3;
        double l12 = sqrt((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        double l13 = sqrt((x3-x1)*(x3-x1) + (y3-y1)*(y3-y1));
        double l23 = sqrt((x3-x2)*(x3-x2) + (y3-y2)*(y3-y2));
        double h = (l12 + l23 + l13) / 2;
        double area = sqrt(h*(h-l12)*(h-l13)*(h-l23));
        if (area <= mina) {
            mina = area;
            mini = i;
        }
        if (area >= maxa) {
            maxa = area;
            maxi = i;
        }
        printf("l12=%f,l13=%f,l23=%f, h=%f, area=%f\n",l12,l13,l23,h,area);
    }
    printf("%d %d\n", mini, maxi);
    return 0;
}
