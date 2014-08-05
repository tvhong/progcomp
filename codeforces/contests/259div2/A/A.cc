#include <cstdio>

using namespace std;

int n;
void printline(int x) {
    int l = 2*x + 1;
    int z = (n - l) >> 1;
    for (int i=0; i<z; i++)
        printf("*");
    for (int i=0; i<l; i++)
        printf("D");
    for (int i=0; i<z; i++)
        printf("*");
    printf("\n");
}
int main() {
    scanf("%d", &n);
    for (int i=0; i<n/2; i++) {
        printline(i);
    }
    for (int i=n/2; i>=0; i--) {
        printline(i);
    }
    return 0;
}
