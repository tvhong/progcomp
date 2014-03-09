#include <bits/stdc++.h>

int main() {
  int sum = 0;
  int n;
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    if (i % 3 == 0 || i % 5 == 0)
      sum += i;
  }
  printf("%d\n", sum);
  return 0;
}
