#include <cstdio>
#include <cmath>

using namespace std;

const int N = 1e5;
int n, m;
int a[N];
int apr[N][10];

int main() {
  scanf("%d %d", &n, &m);
  for (int i=0; i<n; i++) {
    char ch;
    scanf(" %c", &ch);
    ch -= '0';
    a[i] = ch;
    if (i > 0) {
      for (int j=0; j<=9; j++) {
        apr[i][j] = apr[i-1][j];
        if (j == a[i]) apr[i][j]++;
      }
    } else {
      apr[i][a[i]] = 1;
    }
  }
  /*
  for (int i=0; i<n; i++) {
    for (int j=0; j<=9; j++) {
      printf("%d ", apr[i][j]);
    }
    printf("\n");
  }
  */
  for (int i=0; i<m; i++) {
    int j;
    scanf("%d", &j);
    j--;
    if (j == 0) {
      printf("0\n");
    } else {
      int res = 0;
      for (int k = 0; k < 10; k++) {
        res += apr[j-1][k] * abs(k-a[j]);
      }
      printf("%d\n", res);
    }
  }
  return 0;
}
