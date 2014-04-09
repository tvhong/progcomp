/*
 * Things I learnt:
 * .  We can store big numbers by char[]
 * .  Exposed to multiplying big numbers using accumulative approach
 *    with carry over
 */
#include <cstdio>

int t, n, ndigits;
char res[200];

int mul(int i) {
  int accum, carry = 0; // the carry can be very large when i is large
  for (int j=0; j<ndigits; j++) {
    accum = carry + res[j] * i;
    res[j] = accum % 10;
    carry = accum / 10;
  }
  while (carry) {
    res[ndigits++] = carry%10;
    carry /= 10;
  }
}

int fact() {
  res[0] = 1;
  ndigits = 1;
  for (int i=1; i<=n; i++) {
    mul(i);
  }
}

int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    fact();
    for (int i=ndigits-1; i>=0; i--)
      printf("%d", res[i]);
    printf("\n");
  }
  return 0;
}
