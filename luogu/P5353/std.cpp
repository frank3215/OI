#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=5e5+5,base1=20041001,base2=20040607,md1=167772161,md2=104857601;
int n,F[19][N],head[N],cnt,dep[N],x[N],y[N],c[N],sa[N],hx1[N],hx2[N];
char s[N];
vector<int>vec[N],vd[N];
vector<pair<int,int>>pd[N];
struct edge{
	int to,nxt;
}e[N];
void dfs(int now){
	hx1[now]=((LL)hx1[F[0][now]]*base1+s[now])%md1,hx2[now]=((LL)hx2[F[0][now]]*base2+s[now])%md2;
	for(int i=head[now];i;i=e[i].nxt)dep[e[i].to]=dep[now]+1,F[0][e[i].to]=now,dfs(e[i].to);
}
void ssort(){
	int m=256;
	for(int i=1;i<=m;++i)c[i]=0;
	for(int i=1;i<=n;++i)++c[x[i]=s[i]];
	for(int i=1;i<=m;++i)c[i]+=c[i-1];
	for(int i=n;i;--i)sa[c[x[i]]--]=i;
	for(int k=0;1<<k<=n;++k){
		for(int i=1;i<=n;++i)vec[i].clear();
		for(int i=1;i<=n;++i)if(F[k][i])vec[F[k][i]].push_back(i);
		int p=0;
		for(int i=1;i<=1<<k;++i)
		for(int j:vd[i])y[++p]=j;
		for(int i=1;i<=n;++i)
		for(int j:vec[sa[i]])y[++p]=j;
		for(int i=1;i<=m;++i)c[i]=0;
		for(int i=1;i<=n;++i)++c[x[i]];
		for(int i=1;i<=m;++i)c[i]+=c[i-1];
		for(int i=n;i;--i)sa[c[x[y[i]]]--]=y[i];
		std::swap(x,y);
		x[sa[1]]=p=1;
		for(int i=2;i<=n;++i)
		x[sa[i]]=(y[sa[i]]==y[sa[i-1]]&&y[F[k][sa[i]]]==y[F[k][sa[i-1]]]?p:++p);
		if(p==n)break;
		m=p;
	}
}
inline int cmp(int a,int b){return F[0][a]!=F[0][b]?x[F[0][a]]<x[F[0][b]]:a<b;}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=2;i<=n;++i){
		int&f=F[0][i];
		cin>>f;
		e[++cnt]=(edge){i,head[f]},head[f]=cnt;
	}
	cin>>(s+1);
	dfs(dep[1]=1);
	for(int i=1;i<=n;++i)vd[dep[i]].push_back(i);
	for(int i=1;i<19;++i)
	for(int j=1;j<=n;++j)
	F[i][j]=F[i-1][F[i-1][j]];
	ssort();
	int lst=1;
	for(int i=2;i<=n+1;++i)
	if(hx1[sa[i]]!=hx1[sa[i-1]]||hx2[sa[i]]!=hx2[sa[i-1]])pd[dep[sa[i-1]]].emplace_back(lst,i-1),lst=i;
	for(int i=1;i<=n;++i)
	for(auto j:pd[i]){
		sort(sa+j.first,sa+j.second+1,cmp);
		for(int k=j.first;k<=j.second;++k)
		x[sa[k]]=k;
	}
	for(int i=1;i<=n;++i)cout<<sa[i]<<' ';
	return 0;
}
