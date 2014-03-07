#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <deque>

#define s(x) scanf("%d", &x)

using namespace std;
int main() {
    deque<int> a, r;
    int n, p, k, i, j, nn;
    s(n);
    s(k);
    s(p);
    for (i=1; i<=k; i++) {
        a.push_back(i);
    }
    //System.out.println(a.toString());
    for (i=1; i<=k; i++) {
        if (i % n == 0) r.push_front(a.front()); // her card
        a.pop_front();    // give card
        //move cards
        for (j=0; j<p; j++) {
            a.push_back(a.front());
            a.pop_front();
        }
    }

    sort(r.begin(), r.end());
    for (deque<int>::iterator it = r.begin(); it!=r.end(); it++) {
        printf("%d\n", *it);
    }
    return 0;
}
