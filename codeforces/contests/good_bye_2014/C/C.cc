#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int N = 505;
const int M = 1005;

int n, m, w[N], b[M], o[N], k;
set<int> on[N];

int main() {
    scanf("%d %d", &n, &m);
    for (int i=0; i<n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i=0; i<m; i++) {
        scanf("%d", &b[i]);
        b[i]--;
    }

    int ans = 0;
    typedef set<int>::iterator it_t;
    for (int i=0; i<m; i++) {
        for (it_t it = on[b[i]].begin(); it != on[b[i]].end(); ++it) {
            ans += w[*it];
        }
        on[b[i]].clear();

        for (int j=0; j<n; j++) {
            if (j == b[i]) continue;
            on[j].insert(b[i]);
        }
    }

    printf("%d\n", ans);
    return 0;
}
