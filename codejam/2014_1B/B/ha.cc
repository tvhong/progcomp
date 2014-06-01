#include <cstdio>

int main() {
  int cnt = 0;
  for (int j = 0; j<100; j++)
    for (int i=0; i<=1e9; i++)
      cnt++;
  printf("%d\n", cnt);
  return 0;
}
