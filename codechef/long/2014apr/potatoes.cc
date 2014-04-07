#include <cstdio>

using namespace std;

int t, x, y;
int isPrime(int x) {
  for (int i=2; i*i<=x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

int main() {
  scanf("%d", &t);
  while (t--) {
    int z;
    scanf("%d %d", &x, &y);
    for (int i=x+y+1; ; i++) {
      //printf("%d\n", i);
      if (isPrime(i)) {
        z = i - x - y;
        break;
      }
    }
    printf("%d\n", z);
  }
  return 0;
}
