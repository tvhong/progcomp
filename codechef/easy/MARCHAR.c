#include <stdio.h>
#include <math.h>

#define s(n) scanf("%d", &n)

int t,n,m,j,yes,power,sum;
unsigned int i;
int a[20];
int main() {
    for (s(t); t--;) {
        //if(t==1) break;
        s(n);
        s(m);
        for(i=0;i<n;i++) {
            s(a[i]);
            //printf("%d ", a[i]);
        }
        //printf("\n");
        yes = 0;
        power = pow(2, n);
        //printf("%d\n", power);
        for (i=0; i<power && yes==0;i++) {
            sum = 0;
            for (j=0;j<n;j++) {
                if ((i & (1<<j)) > 0) {
                    //if (i==23) printf("i&%d ", i&(1<<j));
                    //if (i==23) printf("j%d ", j);
                    sum+=a[j];
                    //if (i==23) printf("a[j]%d ", a[j]);
                }
            }
            if (sum == m) yes = 1;
            //if (i==23) printf("%d\n", sum);
        }
        yes ? printf("Yes\n") : printf("No\n");
    }
    return 0;
}
