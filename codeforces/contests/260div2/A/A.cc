#include <cstdio>
#include <algorithm>
#include <utility>

#define x first
#define y second
using namespace std;

const int N = 1e5 + 5;
int n;
pair<int, int> a[N];

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d %d", &a[i].x, &a[i].y);
    }
    sort(a, a+n);
    int maxqua = 0;
    bool good = false;
    for (int i=0; i<n; i++) {
        if (a[i].y < maxqua) {
            good = true;
            break;
        }
        maxqua = max(maxqua, a[i].y);
    }
    printf("%s\n", good ? "Happy Alex" : "Poor Alex");
    return 0;
}

