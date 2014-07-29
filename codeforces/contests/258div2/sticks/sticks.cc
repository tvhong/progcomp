#include <cstdio>

#define P0 "Akshat"
#define P1 "Malvika"

using namespace std;

int winner, n, m;
int main() {
  scanf("%d %d", &n, &m);
  winner = 1;
  while (n > 0 && m > 0) {
    winner = (winner + 1) % 2;
    n--, m--;
  }
  printf("%s\n", winner ? P1 : P0);

  return 0;
}
