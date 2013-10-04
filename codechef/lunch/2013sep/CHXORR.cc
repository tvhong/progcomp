#include <bits/stdc++.h>
#include <climits>
using namespace std;
#define s(x) scanf("%d", &x)

#define MAX_INT 3e9l
#define SIZE 2010
#define INT_BIT (sizeof(int)*8)
typedef long long ll;

typedef class Node *Link;
class Node {
  public:
    Link l, r;
    int nums;
    Node() {l = r = NULL; nums = 0;}
};

void insert(Link trie, int n) {
    assert(trie != NULL);
    int i;
    //printf("inserting number %d\n", n);
    for (i=INT_BIT-1; i>=0; i--) {
        //printf("tree[%d]=%d, ", i, trie->nums);
        trie->nums++;
        if (n & (1<<i)) {
            if (trie->r == NULL) trie->r= new Node();
            trie = trie->r;
            //printf("move right\n");
        } else {
            if (trie->l == NULL) trie->l= new Node();
            trie = trie->l;
            //printf("move left\n");
        }
    }
    trie->nums++;
}

void remove(Link trie, int n) {
    assert(trie != NULL);
    int i;
    for (i=INT_BIT-1; i>=0; i--) {
        trie->nums--;
        assert(trie->nums >= 0);
        if (n & (1<<i)) {
            assert (trie->r != NULL);
            trie = trie->r;
        } else {
            assert (trie->l != NULL);
            trie = trie->l;
        }
    }
    trie->nums--;
}

#define bit1(i, k) (i&(1<<k))
int searchXOR(Link trie, int i, int j) {
    int p = i^j, r = 0, k;
    int left, il, jl, ir, jr;
    //printf ("i,j=%d,%d\n", i,j);
    for (k=INT_BIT-1; k>=0; k--) {
        if (bit1(i,k)) il = 0; else il = i;
        if (bit1(j,k)) jl = 0; else jl = j;
        if (!bit1(i,k)) ir = 0; else ir = i;
        if (!bit1(j,k)) jr = 0; else jr = j;
        //printf("tree[%d]=%d, ", k, trie->nums);
        //if (k==1) printf("tre2right=%d", trie->r->nums);
        if (trie->r == NULL || trie->r->nums - (ir>0) - (jr>0) == 0) {
            left = 1;
        } else if (trie->l == NULL || trie->l->nums - (il>0) - (jl>0) == 0) {
            left = 0;
        } else {
            if (p&(1<<k)) {
                //go to the opposite side
                left = 1;
            } else {
                assert(trie->r != NULL);
                left = 0;
            }
        }
        if (left) {
            trie = trie->l;
            i = il;
            j = jl;
            //printf("move left\n");
        } else {
            trie = trie->r;
            r |= (1<<k);
            i = ir;
            j = jr;
            //printf("move right\n");
        }
    }
    //printf ("r=%d,res=%d\n", r, r^p);
    return r ^ p;
}

int main() {
    int t, n, i, j;
    int a[SIZE];
    s(t);
    while (t--) {
        Link trie = new Node();
        s(n);
        for (i=0; i<n; i++) {
            s(a[i]);
            insert(trie, a[i]);
        }
        int ans = 0;
        for (i=0; i<n-1; i++)
            for (j=i+1; j<n; j++) {
                //remove(trie, a[i]);
                //remove(trie, a[j]);
                ans = max(ans, searchXOR(trie, a[i], a[j]));
                //insert(trie, a[i]);
                //insert(trie, a[j]);
            }
        printf("%d\n", ans);
    }
    return 0;
}
