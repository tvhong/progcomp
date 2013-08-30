#include <stdio.h>
#define s(n) scanf("%d", &n)

int N,W,i,j,max,min,cnt;
int a[400000];
int main() {
    s(N); s(W);
    s(a[0]);
    max = a[0];
    min = a[0];
    cnt = 0;
    for(i=1;i<W;i++) {
        s(a[i]);
        if (a[i]>max) max = a[i];
        else if (a[i]<min) min = a[i];
    }
    if (max-min<W) {
        cnt++;
        flag = 1;
    }
    for(;i<N;i++) {
        s(a[i]);
        if (flag) 
            
        if ((i-W>=0) && (a[i-W]==max || a[i-W]==min)) {
            max = a[i-(W-1)];
            min = a[i-(W-1)];
            for (j=W-2;j>=0;j--) {
                if (a[i-j]>max) max = a[i-j];
                else if (a[i-j]<min) min = a[i-j];
            }
        } else if (a[i]>max) max = a[i];
        else if (a[i]<min) min = a[i];
        flag = 0;
        if (max-min<W) {
            cnt++;
            flag = 1;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
