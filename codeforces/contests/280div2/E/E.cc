#include <cstdio>
#include <utility>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int, int> pts;
const int N = 1e6 + 5;

int n, m, dx, dy;
map<pts, int> aplCells;
int a[N], rez[N];

int main() {
    scanf("%d %d %d %d", &n, &m, &dx, &dy);
    for (int i=0; i<m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        aplCells[pts(x, y)]++;
    }

    for (int i = 0, x = 0, y = 0; i < n; i++, x = (x + dx) % n, y = (y + dy) % n) {
        //printf("a[%d] = %d\n", x, y);
        a[x] = y;
    }

    memset(rez, 0, sizeof(rez));
    int irez = 0;
    typedef map<pts, int>::iterator it_t;
    for (it_t it = aplCells.begin(); it != aplCells.end(); ++it) {
        int x = it->first.first, y = it->first.second;
        int i = (y + n - a[x]) % n;
        rez[i] += it->second;
        if (rez[i] > rez[irez]) irez = i;
    }
    
    printf("%d %d\n", 0, irez);

    return 0;
}
