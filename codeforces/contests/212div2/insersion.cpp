#include <bits/stdc++.h>

using namespace std;

const int N = 5005;
int d[N][N];
int a[N];
int main() {
  int n;
  scanf("%d", &n);
  for (int i= 0; i < n; i++) {
    scanf("%d", &a[i]);
    d[0][i] = 0;
  }
  /*
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      d[i][j] = 0;
      */
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == 0) {
        d[i][j] = 0;
      } else {
        d[i][j] = d[i-1][j];
      }
      if (j < a[i])
        d[i][j]++;
    }
  }
  /*
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) 
      printf("%d ", d[i][j]);
    printf("\n");
  }
  */

  int inv = 0;
  for (int i = 0; i < n; i++)
    inv += d[i][a[i]];

  //printf("%d\n", inv);
  int min_inv = inv;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (a[i] > a[j]) {
        int new_inv = inv - 2*(d[i][a[i]] + d[j][a[j]] - d[i][a[j]] - d[j][a[i]]) - 1;
        //printf("%d\n", new_inv);
        if (new_inv < min_inv) {
          min_inv = new_inv;
          cnt = 1;
        } else if (new_inv == min_inv) {
          cnt++;
        }
      }
    }
  }

  printf("%d %d\n", min_inv, cnt);

  return 0;
}
