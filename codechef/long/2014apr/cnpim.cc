#include <cstdio>
#include <cstring>

using namespace std;

const int N = 2505;
int t, n, f[N*N], lprod[N*N], primes[N*N], notprime[N*N];
int p;

void pre() {
  p = 0;
  memset(notprime, 0, sizeof notprime);
  for (int i=2; i<N*N; i++) {
    if (notprime[i]) continue;
    //printf("p=%d i=%d\n", p, i);
    primes[p++] = i;
    for (int j=i; j<N*N; j+=i)
      notprime[j] = 1;
  }
  /*
  for (int i=0; i<10; i++)
    printf("%d\n", primes[i]);
    */
  for (int i=1; i<N*N; i++) {
    int f[i] = 1;
    int tmp = i;
    for (int j=0; j<p && tmp>=primes[j]; j++){
      int pw = 0;
      //printf("%d\n", primes[j]);
      while (tmp>=primes[j] && tmp % primes[j] == 0) pw++, tmp /= primes[j];
      f[i] *= (pw+1);
    }
    lprod[i] = lprod[i-1] + f[i];
    //if (i<50) printf("%d %d\n", i, ndiv);
  }
  printf("done\n");
}


int main() {
  pre();
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", (n-1) * lprod[n-1]);
  }
  return 0;
}
