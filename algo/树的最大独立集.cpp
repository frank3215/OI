#include <cstdio>
#include <vector>
const int maxn=10000
int n,a,b,i,dp[maxn],gs[maxn],s[maxn],dad[maxn];
vector<int> tree[maxn];
int dp(int node){
	if(res[node]!=-1) return res[node];
	int d=dad[node];
	if(d){
		dp[dad[node]]++;

	for(int j=0;j<tree[node].size();j++){
		dp(tree[node][j]);
	}
	return res[node]
}
int main(){
	scanf("%d",&n);
	res[0]=-1;
	for(i=1;i<n;i++){
		scanf("%d %d",&a,&b);
		tree[a].push_back(b);
		dad[b]=a;
		res[i]=-1;
	}
	printf("%d\n",dp(0));
	return 0;
}
