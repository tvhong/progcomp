#include <cstdio>

#define SIZE 100
char a[SIZE][SIZE];
int cnt[SIZE][SIZE];
int visited[SIZE][SIZE];
int main() {
    int r, s, i, j, k, tr, ts, nseat = 1;
    scanf("%d %d\n", &r, &s);
    for (i=0; i<r; i++) {
        for (j=0; j<s; j++) {
            char ch = getchar();
            //putchar(ch);
            //printf("i=%d, %d\n", i, j);
            a[i][j] = ch;
            if (a[i][j] == 'o') {
                for (k=0; k<9; k++) {
                    if (k == 4)
                        continue;
                    int tr = i-1 + (k / 3);
                    int ts = j-1 + (k % 3);
                    //printf("%d, %d\n", tr, ts);
                    if (tr >= 0 && tr < r && ts >= 0 && ts < s)
                        cnt[tr][ts]++;
                }
            } else {
                nseat = 0;
            }
        }
        if (i < r-1) scanf("\n");
    }

    int max = 0;
    int ans = 0;
    for (i=0; i<r; i++) {
        for (j=0; j<s; j++) {
            if (cnt[i][j] > max)
                max = cnt[i][j];
            if (a[i][j] == 'o')
                for (k=0; k<9; k++) {
                    if (k == 4) continue;
                    int tr = i-1 + (k / 3);
                    int ts = j-1 + (k % 3);
                    if (tr >= 0 && tr < r && ts >= 0 && ts < s &&
                        a[tr][ts] == 'o' && !visited[tr][ts])
                        ans++;
                }
            visited[i][j] = 1;
        }
    }
    if (!nseat)
        ans += max;
    printf("%d\n", ans);
    /*
    for (i=0; i<r; i++) {
        for (j=0; j<s; j++) {
            printf("%d", cnt[i][j]);
        }
        printf("\n");
    }
    */



    return 0;
}
