#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
using std::min;
using std::cin;
const int n2=65537,N=17,inf=2e9;
int n,m,r,c,a[N][N],e[N],ans=2e9,
	d[N][N],f[N][N],mn[N],p[2*N],cnt[n2];
inline int lb(int x){return x&-x;}
inline int A(int x,int y){return a[x][p[lb(y)%37]];}
int main(){
	cin >> n >> m >> r >> c;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	//Pre
	for(int i=0;i<m;i++)
		p[(1<<i)%37]=i;
	for(int i=1;i<(1<<m);i++)
		cnt[i]=cnt[i^lb(i)]+1;
	for(int i,j,l,k=1;k<(1<<m);k++) if(cnt[k]==c){
		//One row
		memset(d,0,sizeof d);
		memset(e,0,sizeof e);
		memset(f,0x7f,sizeof f);
		for(int i=0,j;i<n;i++)
			for(int j=k;lb(j)!=j;j-=lb(j))
				e[i]+=abs(A(i,j)-A(i,j^lb(j)));
		//Difference between two rows: i,j
		for(int i=0;i<n;i++)
			for(int j=0;j<i;j++)
				for(int l=k;l;l-=lb(l)){
					d[i][j]+=abs(A(i,l)-A(j,l));
				}
		//DP
		for( i=0;i<n;i++){
			f[1][i]=e[i];
			for( l=2;l<=i+1;l++)
				for( j=0;j<i;j++)
					f[l][i]=min(f[l][i],d[i][j]+f[l-1][j]+f[1][i]);
			if(i+1>=r) ans=min(ans,f[r][i]);
		}
	}
	printf("%d\n",ans);
}
