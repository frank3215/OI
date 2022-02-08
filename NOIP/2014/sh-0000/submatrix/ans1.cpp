#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
using std::min;
using std::cin;
const int n2=65537,N=17,inf=2e9;
int n,m,r,c,a[N][N],l[n2],e[N][n2],ans=2e9,
	d[N][N][n2],f[N][N],mn[N][n2],p[n2],cnt[n2];
inline int lb(int x){return x&-x;}
inline int A(int x,int y){return a[x][p[lb(y)]];}
int main(){
	cin >> n >> m >> r >> c;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> a[i][j];
	//Pre
	for(int i=0;i<m;i++)
		p[1<<i]=i;
	for(int i=1;i<(1<<m);i++)
		cnt[i]=cnt[i^lb(i)]+1;
	//One row
	for(int i=0,j;i<n;i++)
		for( j=1;j<(1<<m);j++)
			if(j!=lb(j) && cnt[j] <= c)
				e[i][j]=e[i][j^lb(j)]+abs(A(i,j)-A(i,j^lb(j)));
	//Difference between two rows: i,j
	for(int i=0,j,k;i<n;i++)
		for( j=0;j<i;j++)
			for( k=1;k<(1<<m);k++) if(cnt[k] <= c)
				d[i][j][k]=d[i][j][k^lb(k)]+abs(A(i,k)-A(j,k));
	//DP
	for(int i,j,l,k=1;k<(1<<m);k++) if(cnt[k]==c){
		memset(f,0x7f,sizeof f);
		for( i=0;i<n;i++){
			f[1][i]=e[i][k];
			for( l=2;l<=i+1;l++)
				for( j=0;j<i;j++)
					f[l][i]=min(f[l][i],d[i][j][k]+f[l-1][j]+f[1][i]);
			if(i+1>=r) ans=min(ans,f[r][i]);
		}
	}
	printf("%d\n",ans);
}
