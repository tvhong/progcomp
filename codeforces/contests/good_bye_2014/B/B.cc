#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int N = 305;
typedef pair<int, int> pts;

int n, a[N];

map<int, set<int> > groups;

int parent[N];
int root(int i) {
    int p = parent[i];
    return parent[p] == p ? p : parent[i] = root(p);
}

void join(int i, int j) {
    int u = root(i), v = root(j);
    if (u == v) return;
    if (rand() & 1)
        parent[u] = v;
    else
        parent[v] = u;
}

int main() {
    scanf("%d", &n);
    for (int i =0; i<n; i++) {
        scanf("%d", &a[i]);
        parent[i] = i;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            char ch;
            scanf(" %c", &ch);
            if (ch == '1') join(i, j);
        }
    }

    for (int i = 0; i<n; i++) {
        groups[root(i)].insert(i);
    }

    typedef map<int, set<int> >::iterator itm_t;
    typedef set<int>::iterator its_t;
    for (itm_t it = groups.begin(); it != groups.end(); ++it) {
        vector<int> vals, ids;
        for (its_t it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            int i = *it2;
            ids.push_back(i);
            vals.push_back(a[i]);
        }
        sort(vals.begin(), vals.end());
        for (int i=0; i<ids.size(); i++) {
            a[ids[i]] = vals[i];
        }
    }

    for (int i=0; i<n; i++) {
        printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
    }
    return 0;
}
