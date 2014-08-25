#include <cstdio>
#include <algorithm>

const int N = 1e5;
int n;
int main() {
    scanf("%d", &n);
    int a = 1;
    for (int k = 2; k<=4; k++) {
        int b = 1;
        for (int i=0; i<n; i++) {
            b = (b * k) % 5;
        }
        a = (a + b) % 5;
    }
    printf("%d\n", a);
    return 0;
}
