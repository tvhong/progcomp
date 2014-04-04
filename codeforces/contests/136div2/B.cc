#include <bits/stdc++.h>

using namespace std;

int n;
int dig[10] = {0};

bool same_digit(int i) {
  while (i > 0) {
    if (dig[i%10]) return true;
    i /= 10;
  }
  return false;
}

int main() {
  scanf("%d", &n);
  int tmp = n;
  while (tmp > 0) {
    dig[tmp%10]++;
    tmp /= 10;
  }
  int cnt = 0;
  for (int i=1; i*i<=n; i++) {
    if (n % i == 0) {
      if (same_digit(i)) cnt++;
      if (i*i != n && same_digit(n/i)) cnt++;
    }
  }
  printf("%d\n", cnt);
  return 0;
}
