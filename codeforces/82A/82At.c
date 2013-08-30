#include <stdio.h>

int main() {
  int n;
  char *a[] = {"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};
  scanf("%d", &n);
  n--;
  while (n>=5) {
    n -= 5;
    n = n / 2;
  }
  printf("%s\n", a[n]);
  return 0;
}
