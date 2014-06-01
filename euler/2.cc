#include <cstdio>

using namespace std;

int n, ans;
void fib(int f1, int f2) {
  int f3 = f1 + f2;
  //printf("f3= %d\n", f3);
  if (f3 > n) {
    return;
  }
  if (!(f3&1)) ans += f3;
  fib(f2, f3);
}
int main() {
  scanf("%d", &n);
  ans = 2;
  fib(1, 2);
  printf("%d\n", ans);
  return 0;
}
