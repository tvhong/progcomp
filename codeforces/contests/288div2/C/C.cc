#include <cstdio>
using namespace std;

const int N = 350;
int m, t, r, w[N], tot, candle_life[N];

int main() {
    tot = 0;
    scanf("%d%d%d", &m, &t, &r);
    if (t < r) {
        printf("-1\n");
        return 0;
    }
    for (int i=0; i<m; i++) {
        scanf("%d", &w[i]);
        int still_burning = 0;
        int w_diff = (i == 0) ? 0 : w[i] - w[i-1];
        for (int j=1; j<=t; j++) {
            if (j - w_diff > 0) {
                still_burning += candle_life[j];
                candle_life[j - w_diff] += candle_life[j];
            }
            candle_life[j] = 0;
        }
        int needto_light = r - still_burning;
        for (int i=0; i<needto_light; i++) {
            candle_life[t-i]++;
        }
        tot += needto_light;
    }
    printf("%d\n", tot);
    return 0;
}
