#include <cstdio>

using namespace std;

int n, m;

int main() {
    scanf("%d %d", &m, &n);
    printf("n = %d, m = %d\n", n, m);
    if (m == 1) {
        //TODO:
    }
    double b = 1.0*(m-1)/m;
    double nom = 1;
    for (int i=0; i<n; i++)
        nom *= b;
    double tmp = 1;
    printf("b=%f, nom=%f\n", b, nom);
    double ans = 0;
    for (int i=m; i>=1; i--) {
        double p = (1 - nom) * tmp;
        printf("i=%d, p=%f\n", i, p);
        ans += p * i;
        tmp *= nom;
    }
    printf("%f\n", ans);
    return 0;
}
