#include <stdio.h>

void categorise();
int filter2();
int match(int cat1, int cat2);
void solve();

int t, n, x, y;
int a[4][4];

int main() {
  scanf("%d", &t);
  while (t) {
    int i, j;
    for (i = 0; i < 4; i++)
      for (j = 0; j < 4; j++)
        a[i][j] = 0;

    scanf("%d", &n);
    while (n) {
      scanf("%d %d", &x, &y);
      n--;
      //if (x == 0 || y == 0) continue;
      categorise(a, x, y);
    }
    solve();
    t--;
  }
  return 0;
}

void solve() {
  int i, j, k, l;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      printf("a[%d][%d] = %d\n", i, j, a[i][j]);
    }
  }

  int sum = 0;
  int gcdEven = 0;
  for (i = 0; i < 4; i++) {
    for (j = 0; j < 4; j++) {
      for (k = 0; k < 4; k++) {
        for (l = 0; l < 4; l++) {
          if (match(i, j)) gcdEven++;
          if (match(j, k)) gcdEven++;
          if (match(k, l)) gcdEven++;
          if (match(l, i)) gcdEven++;
          if (gcdEven % 2 == 0) {
            if (a[0][i] * a[1][j] * a[2][k] * a[3][l] > 0)
              printf("%d %d %d %d, %d\n", i, j, k, l, a[0][i] * a[1][j] * a[2][k] * a[3][l]);
              sum += a[0][i] * a[1][j] * a[2][k] * a[3][l];
          }
        }
      }
    }
  }
  printf("%d\n", sum);
}

void categorise() {
  int category;
  if (x > 0 && y > 0) category = 0;
  else if (x > 0 && y < 0) category = 1;
  else if (x < 0 && y < 0) category = 2;
  else if (x < 0 && y > 0) category = 3;
  int index2 = filter2(a, x, y);
  a[category][index2]++;
}

int filter2() {
  if (x & 1 && y & 1) return 0;
  if (!(x & 1) && !(y & 1)) return 1;
  if (x & 1 && !(y & 1)) return 2;
  return 3;
}

int match(int fil1, int fil2) {
  return (fil1 == fil2);
}
