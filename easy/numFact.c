#include <stdio.h>
#include <math.h>

#define HUNTHOU 100000

int prime[HUNTHOU];
int primePower[HUNTHOU];

/*
int isPrime(int n) {
  if (n == 2) return 1;
  if (n <= 1) return 0;
  int i = 3;
  int sqr = 9;
  while (sqr <= n) {
    if (n % i == 0) return 0;
    i += 2;
    sqr = i * i;
  }
  return 1;
}
*/

void init() {
  int i, j, k;

  prime[0] = 2;
  k = 1;
  for (i = 3; i <= HUNTHOU; i+=2) {
    int isPrime = 1;
    int rootI = (int) sqrt(i);
    //printf("%d\n", rootI);
    for (j = 0; prime[j] <= rootI && isPrime; j++) {
      if (i % prime[j] == 0) isPrime = 0;
    }
    if (isPrime) prime[k++] = i;
    //printf("%d\n", prime[k-1]);}
    
    /*
    if (isPrime(i)) prime[j] = i;
    j++;
    */
  }
}

int factor(int n) {
  int i = 0;
  while (n != 1) {
    while (n % prime[i] == 0) {
      primePower[i]++;
      n /= prime[i];
    }
    i++;
  }
  return i;
}

int main() {
  int t, n, i, val;
  init();
  for (scanf("%d", &t); t--;) {
    //clean primePower;
    for (i = 0; i < HUNTHOU; i++)
      primePower[i] = 0;
    int maxPrimeIndex = 0;
    int primeIndex;
    for (scanf("%d", &n); n--;) {
      scanf("%d", &val);
      primeIndex = factor(val);
      if (primeIndex > maxPrimeIndex) maxPrimeIndex = primeIndex;
    }
    int result = 1;
    for (i = 0; i < maxPrimeIndex; i++)
      result *= primePower[i]+1;
    printf("%d\n", result);
  }
  return 0;
}
