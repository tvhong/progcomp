#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define sz(x) ((int)(x).size())
#define x first
#define y second
typedef long long ll;
inline int getint() { int a; scanf("%d", &a); return a; }
// lexicographically next bitset with the same number of bits set
int nextComb(int x){ // x = xxx0 1111 0000
    if(!x){
        fprintf(stderr, "nextComb(0) called num_vert");
        return ((1<<30)-1+(1<<30));
    }
    int smallest = x&-x; // 0000 0001 0000
    int ripple = x+smallest; // xxx1 0000 0000
    int ones = x^ripple; // 0001 1111 0000
    ones = (ones>>2)/smallest; // 0000 0000 0111
    return ripple|ones; // xxx1 0000 0111
}
map<string,int> cache;
int getid(string s){
    if(!cache.count(s)){
        int t = sz(cache);
        cache[s] = t;
    }
    return cache[s];
}
// Union-Find - A disjoint set data structure
const int N = 1<<6;
int P[N], R[N];
void init(int n){
    for(int i=0; i<n; ++i){
        P[i] = i;
        R[i] = 1;
    }
}
int findP(int x){
    if(P[x] != x)
        P[x] = findP(P[x]);
    return P[x];
}
int merge(int a, int b){
    int pa=findP(a), pb=findP(b);
    if(pa == pb)
        return 0;
    if(R[pa] < R[pb])
        P[pa] = P[pb];
    else{
        P[pb] = P[pa];
        if(R[pa] == R[pb])
            ++R[pa];
    }
    return 1;
}
// O(n) cycle detection - This function returns 1 if a cycle is found, and 0 otherwise
// seen[i] = 0 --> the node has not yet been visited
// seen[i] = 1 --> the node is currently on the stack
// seen[i] = 2 --> the node is not on the stack, and has been completely expanded
int tarjan(int i, vector< vector<int> > &a, vector<int> &seen){
    if(seen[i] == 1)
        return 1;
    if(seen[i] == 2)
        return 0;
    seen[i] = 1;
    for(int j=0; j<sz(a[i]); ++j)
        if(tarjan(a[i][j], a, seen))
            return 1;
    seen[i] = 2;
    return 0;
}
int main(){
    int num_edges;
    while( (num_edges=getint()) ){
        // read in the initial graph
        cache = map<string,int>();
        vector< pair< pair<int,int>,int > > b; // A->B, ?L
        for(int i=0; i<num_edges; ++i){
            string sx, sy, sz;
            cin >> sx >> sy >> sz;
            int x=getid(sx), z=getid(sz);
            if(sy == "D")
                swap(x, z);
            b.push_back(mp(mp(x,z),sy=="L"));
        }
        int num_vert = sz(cache);
        // start taking things out of it
        for(int drop=0; drop<5; ++drop) // brute force the number of things to drop (0..4)
            for(int in=(1<<(num_edges-drop))-1; in<(1<<num_edges); in=nextComb(in)){ // try all bit sets with drop bits missing
                // construct equivalency classes
                init(num_vert);
                for(int i=0; i<num_edges; ++i)
                    if( in&(1<<i) && b[i].y )
                        merge(b[i].x.x, b[i].x.y);
                // perform coordinate compression - this is not necessary
                vector<int> classes;
                for(int i=0; i<num_vert; ++i)
                    if(findP(i) == i)
                        classes.pb(i);
                sort(classes.begin(), classes.end());
                // construct the graph that is meant to be a dag
                vector< vector<int> > a(sz(classes));
                for(int i=0; i<num_edges; ++i)
                    if( in&(1<<i) && !b[i].y ){
#define all(x) (x).begin(), (x).end()
                        int from = lower_bound(all(classes), findP(b[i].x.x))-classes.begin();
                        int to = lower_bound(all(classes), findP(b[i].x.y))-classes.begin();
                        a[from].push_back(to);
                    }
                // test if it is a dag
                // find all nodes with no predecessor
                vector<int> noIncoming(sz(a), 1);
                for(int i=0; i<sz(a); ++i)
                    for(int j=0; j<sz(a[i]); ++j)
                        noIncoming[a[i][j]] = 0;
                // dfs from them checking we don’t find any cycles
                int ok = 1;
                vector<int> seen(sz(a), 0);
                for(int i=0; i<sz(a); ++i)
                    if(noIncoming[i])
                        if(tarjan(i, a, seen))
                            ok = 0;
                // check we visited everybody, it may be the case that we don’t even check people because
                // they are in a cycle with no on ramps
                for(int i=0; i<sz(a); ++i)
                    if(!seen[i])
                        ok = 0;
                // if we never find a cycle, we are done
                if(ok){
                    printf("%d\n", drop);
                    goto next_case;
                }
            }
        printf("5\n");
next_case:
        continue;
    }
    return 0;
}
