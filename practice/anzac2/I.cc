#include <bits/stdc++.h>


using namespace std;

int main() {
  int  d;
  char ch;
  scanf("%d%c", &d, &ch);
  if (d <= 2) {
    printf("%s\n", (ch == 'A' || ch == 'D') ? "window" : "aisle");
  } else if (d <= 20) {
    if (ch == 'A' || ch == 'F') {
      printf("window\n");
    } else {
      printf("aisle\n");
    }
  } else {
    if (ch == 'A' || ch == 'K') {
      printf("window\n");
    } else {
      if (ch == 'C' || ch == 'D' || ch == 'G' || ch == 'H')
        printf("aisle\n");
      else
        printf("neither\n");
    }
  }
  return 0;
}
