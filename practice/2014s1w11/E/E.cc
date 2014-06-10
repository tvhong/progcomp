#include <cstdio>
#include <stack>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <utility>

#define x first
#define y second
#define mp make_pair

#define SUM 45
#define PROD 362880

#define r(k)  (k/9)
#define c(k)  (k%9)
#define sg(k) ((k/27)*3 + (k%27%9)/3)
using namespace std;
const int N = 81;

typedef struct group {
  int sum, prod;
  int mask[10];
} group;

group rows[9], cols[9], subgrids[9];
char board[100], sol[100];
bool done;

void init() {
  for (int i=0; i<9; i++) {
    rows[i].sum = 0;
    rows[i].prod = 1;
    memset(rows[i].mask, 0, sizeof rows[i].mask);

    cols[i].sum = 0;
    cols[i].prod = 1;
    memset(cols[i].mask, 0, sizeof cols[i].mask);

    subgrids[i].sum = 0;
    subgrids[i].prod = 1;
    memset(subgrids[i].mask, 0, sizeof subgrids[i].mask);
  }
  done = false;
}

void recurse(int k) {
  //printf("k=%d\n", k);
  //printf("%s\n", sol);
  if (k == N) {
    done = true;
    printf("%s\n", sol);
  }
  if (board[k] == '.') {
    int i = r(k), j = c(k), l = sg(k);
    for (int v = 9; v>=1 && !done; v--) {
      if (rows[i].mask[v] || cols[j].mask[v] || subgrids[l].mask[v])
        continue;
      rows[i].mask[v] = 1;
      cols[j].mask[v] = 1;
      subgrids[l].mask[v] = 1;
      sol[k] = v+'0';

      recurse(k+1);
      rows[i].mask[v] = 0;
      cols[j].mask[v] = 0;
      subgrids[l].mask[v] = 0;
      sol[k] = '.';
    }
  } else {
    if (!done)
      recurse(k+1);
  }
}

void nonre() {
  stack<pair<int, int> > stack;
  stack.push(mp(0, 0));
  while (!stack.empty()) {
    pair<int, int> st = stack.top();
    stack.pop();
    int k = st.x;
    //printf("k=%d, st.y = %d\n", k, st.y);
    if (k == N) break;
    if (board[k] != '.') {
      stack.push(mp(k+1, 0)); // ignore this state
      continue;
    }
    int i = r(k), j = c(k), l = sg(k);
    if (st.y != 0) {
      /* unfold stuffs */
      rows[i].mask[st.y] = 0;
      cols[j].mask[st.y] = 0;
      subgrids[l].mask[st.y] = 0;
    }
    for (int v = st.y+1; v<=9; v++) {
      if (rows[i].mask[v] || cols[j].mask[v] || subgrids[l].mask[v])
        continue;
      rows[i].mask[v] = 1;
      cols[j].mask[v] = 1;
      subgrids[l].mask[v] = 1;
      sol[k] = v + '0';
      stack.push(mp(k, v));   // store myself
      stack.push(mp(k+1, 0));   // command the next one
      break;
    }
  }
  printf("%s\n", sol);
}

int main() {
  while (scanf("%s", &board), strcmp(board, "end") != 0) {
    assert(strlen(board) == N);
    strncpy(sol, board, 100);
    init();
    for (int k=0; k<N; k++) {
      if (board[k] == '.') continue;
      int num = board[k] - '0';
      int i = r(k), j = c(k), l = sg(k);
      //printf("k=%d, i=%d, j=%d, l=%d\n", k, i, j, l);
      //rows[i].sum += num;
      //rows[i].prod *= num;
      rows[i].mask[num] = 1;
      //cols[j].sum += num;
      //cols[j].prod *= num;
      cols[j].mask[num] = 1;
      //subgrids[l].sum += num;
      //subgrids[l].prod *= num;
      subgrids[l].mask[num] = 1;
    }
    //recurse(0);
    nonre();
  }
  return 0;
}
