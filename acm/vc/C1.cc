#include <cstdio>
#include <cstdlib>
#include <list>

#define s(x) scanf("%d", &x)
#define SIZE 100010

using namespace std;
int debug = 1;
int main() {
    int m, n, p, k, i, j, nn;
    list<int> a, r;
    s(n);
    s(k);
    s(p);
    m = k / n;
    for (i=1; i<=k; i++) {
        a.push_back(i);
    }

    if (debug) 
        for (list<int>::iterator it = a.begin(); it!=a.end(); it++)
            printf("%d\n", *it);

    list<int>::iterator it = a.begin();
    if (debug) printf("*it=%d\n", *it);
    for (i=0; i<m; i++) {
        if (debug) printf("i=%d\n", i);
        for (nn=0; nn<n; nn++) {
            if (debug) printf("nn=%d\n", nn);
            if (nn == n-1) r.push_front(*it); // her card

            list<int>::iterator itt = it;
            it++;
            if (it == a.end()) it = a.begin();

            if (debug) printf("remove: %d\n", *itt);
            a.erase(itt);    // give card
            if (debug)
                for (list<int>::iterator it = a.begin(); it!=a.end(); it++)
                    printf("%d\n", *it);

            if (p >= a.size()) continue;
            //move cards
            for (j=0; j<p; j++) {
                if (debug) printf("*it=%d\n", *it);
                it++;
                if (it == a.end()) it = a.begin();
            }
        }
    }

    r.sort();
    for (list<int>::iterator it = r.begin(); it!=r.end(); it++) {
        printf("%d\n", *it);
    }

    return 0;
}
