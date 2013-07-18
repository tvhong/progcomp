#include <stdio.h>
#include <stdlib.h>

#define ULLONG_MAX 18446744073709551615llu;

unsigned long long t, n, m, i, j, k, v, result;
unsigned long long price[100][100], discounted[100][100], d[100][100];
int main() {
  for (scanf("%llu", &t); t--;) {
    scanf("%llu", &n);
    scanf("%llu", &m);
    /*
    price = malloc(sizeof(int*) * n);
    for (i = 0; i < n ; i++) {
      price[i] = malloc(sizeof(int) * m);
    }
    */

    for (i = 0; i < n ; i++)
      for (j = 0; j < m ; j++) {
        scanf("%llu", &price[i][j]);
        //printf("%llu ", price[i][j]);
      }

    for (i = 0; i < n ; i++)
      for (j = 0; j < m ; j++) {
        scanf("%llu", &discounted[i][j]);
        //printf("%llu ", discounted[i][j]);
        d[i][j] = ULLONG_MAX;
      }

    for (j = 0; j < m ; j++)
      d[0][j] = price[0][j];

    for (i = 1; i < n ; i++) {
      for (j = 0; j < m ; j++) {
        for (k = 0; k < m ; k++) {
          v = d[i - 1][k] + price[i][j];
          if (j == k) v -= discounted[i-1][k];
          if (v < 0) v = 0;
          if (d[i][j] > v) d[i][j] = v;
        }
      }
    }

    /*
    for (i = 0; i < n ; i++) {
      for (j = 0; j < m ; j++)
        printf("%llu ", d[i][j]);
      printf("\n");
    }
    */
    result = d[n - 1][0];
    for (j = 1; j < m; j++)
      if (result > d[n - 1][j]) result = d[n-1][j];

    printf("%llu\n", result);
  }

  return 0;
}
