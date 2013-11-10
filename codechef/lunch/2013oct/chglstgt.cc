#include <cstdio>

#define SIZE 5010
using namespace std;

int isPal(int* a, int i, int j) {
    while (i < j && a[i] == a[j]) {
        i++;
        j--;
    }
    return (i >= j);
}
int main() {
    int t, n, i, j;
    int a[SIZE], cnt[SIZE], lone[SIZE];
    scanf("%d", &t);
    while (t--) {
        scanf("%d\n", &n);
        for (i=0; i<n; i++)
            a[i] = getchar();

        cnt[0] = 1;
        lone[0] = 1;
        for (i=1; i<n; i++) {
            lone[i] = 1;
            cnt[i] = cnt[i-1] + 1;
            for (j=0; j<i; j++) {
                if (isPal(a, j, i)) {
                    int point;
                    if (lone[j]) point = cnt[j];
                    else point = cnt[j-1] + 1;

                    if (point < cnt[i]) {
                        cnt[i] = point;
                        lone[i] = 0;
                    }
                }
            }
        }
        printf("%d\n", cnt[n-1]);
    }
    return 0;
}
