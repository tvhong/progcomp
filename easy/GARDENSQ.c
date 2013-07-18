#include <stdio.h>
#define s(n) scanf("%d", &n)

int i,j,k,t,m,n,cnt;
char a[50][51];
int main() {
    s(t);
    while(t--) {
        s(n); s(m);
        for(i=0;i<n;i++)
            scanf("%s", a[i]);
        cnt = 0;
        for(i=0;i<n-1;i++) {
            for(j=0;j<m-1;j++) {
                k = 1;
                while(i+k<n && j+k<m) {
                    if(a[i][j]==a[i][j+k] && a[i][j]==a[i+k][j] && a[i][j]==a[i+k][j+k]) cnt++;
                    k++;
                }
            }
        }
        printf("%d\n", cnt);

    }
    return 0;
}
