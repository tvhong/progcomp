#include <cstdio>
#include <algorithm>
#include <iostream>

using namespace std;

const int N = 27;
const double EPS = 0.0000001;
int n;
double adj[N][N];

int main() {
  while (scanf("%d", &n), n) {
    for (int i=0; i<N; i++)
      for (int j=0; j<N; j++)
        adj[i][j] = 0;
    for (int i=0; i<n; i++) {
      scanf("%c %c %d", &a, &b, &r);
      a -= 'A';
      b -= 'A';
      if (abs(adj[a][b]) > EPS) {
        adj[a][b] = 1.0/(1.0/adj[a][b] + 1.0/r);
      } else {
        adj[a][b] = r;
      }
    }
    BFS();
  }
  return 0;
}
