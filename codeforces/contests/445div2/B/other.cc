#include <cstdio>
#include <algorithm>

long long int ans;
int p[200];

int find(int v){
	if(p[v]==v)return v;
	return (p[v]=find(p[v]));
}

void un(int v1,int v2){
	int p1=find(v1);
	int p2=find(v2);
	if(p1!=p2){
		ans*=2;
		p[p1]=p2;
	}
}

void solve(int n,int m){
	int i,j,k,l;
	ans=1;
	for(i=0;i<n;i++)p[i]=i;
	for(i=0;i<m;i++){
		scanf("%d%d",&k,&l);
		un(k-1,l-1);
	}

	printf("%lld",ans);
}

int main() {
#pragma comment(linker, "/STACK:67108864")	
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		solve(n,m);
	}
	return 0;
}
