#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int t, n, i, j, k, tot;
int a[351][351];
int cracked[351][351];
int primeSize = 50;
int* primes;
int lastPrime;

int isPrime(int x) {
  if (x < 2) return 0;
  if (x < 4) return 1;
  if (x % 2 == 0) return 0;
  int p, q;
  if (x <= primes[lastPrime]) {
    for (p = 0; p <= lastPrime; p++)
      if (x == primes[p]) return 1;
  } else {
    for (p = primes[lastPrime] + 1; p <= x; p++) {
      int s = sqrt(p);
      int isP = 1;
      for (q = 2; q <= s; q++) {
        if (p % q == 0) {
          isP = 0;
          break;
        }
      }
      if (isP) {
        if (lastPrime + 1 == primeSize) {
          primeSize *= 2;
          primes = realloc(primes, sizeof(int) * primeSize);
        }
        primes[++lastPrime] = p;
      }
    }
    if (primes[lastPrime] == x) return 1;
  }
  return 0;
}

void grid(int x, int y) {
  if (cracked[x][y] || isPrime(a[x][y])) return;
  cracked[x][y] = 1;
  if (x - 1 > 0 && (a[x][y] - a[x - 1][y]) % 2 == 0) grid(x - 1, y);
  if (x + 1 <= n && (a[x][y] - a[x + 1][y]) % 2 == 0) grid(x + 1, y);
  if (y - 1 > 0 && (a[x][y] - a[x][y - 1]) % 2 == 0) grid(x, y - 1);
  if (y + 1 <= n && (a[x][y] - a[x][y + 1]) % 2 == 0) grid(x, y + 1);
}

void solve() {
//if even, failed = even / 2 = 
//ex: 4, failed 2 (0, 2)
//if odd, failed (odd + 3 / 2)
//ex: 9, failed 6
//
  tot = 0;
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (cracked[i][j]) continue;
      if (a[i][j] % 2 == 0 && a[i][j] != 2) {
        tot += a[i][j] / 2;
        grid(i, j);
      } else if (!isPrime(a[i][j])) {
        tot += (a[i][j] + 3) / 2;
        grid(i, j);
      } else {
        for (k = 2; k < a[i][j]; k++)
          if (isPrime(k)) tot++;
        cracked[i][j] = 1;
      }
    }
  }
  printf("%d\n", tot);
}

int main() {
  primes = (int*) malloc(sizeof(int) * primeSize);
  primes[0] = 2;
  primes[1] = 3;
  lastPrime = 1;
  /*
  printf("%d\n", isPrime(1));
  printf("%d\n", isPrime(2));
  printf("%d\n", isPrime(3));
  printf("%d\n", isPrime(4));
  printf("%d\n", isPrime(5));
  printf("%d\n", isPrime(6));
  printf("%d\n", isPrime(7));
  printf("%d\n", isPrime(8));
  printf("%d\n", isPrime(9));
  printf("%d\n", isPrime(10));
  for (i = 0; i <= 15; i++) {
    printf("%d\n", primes[i]);
  }
  */

  for (scanf("%d", &t); t--;) {
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) {
        scanf("%d", &a[i][j]);
        cracked[i][j] = 0;
      }
    solve();
  }
  return 0;
}
