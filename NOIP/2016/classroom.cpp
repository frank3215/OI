#include <cstdio>
#include <algorithm>
using std::min;
const int maxn=3010,maxv=410,inf=1e9;
int n,m,v,e,c[4][maxn];
double k[maxn],dp[4][maxn][maxn],tmp;
int a,b,w,f[maxv][maxv];
void read(){
	scanf("%d%d%d%d",&n,&m,&v,&e);
	for(int i=0;i<2;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",c[i]+j);
	for(int i=1;i<=n;i++) scanf("%lf",k+i);
	for(int i=1;i<=v;i++)
		for(int j=1;j<=v;j++)
			f[i][j]=(i==j?0:inf);
	for(int i=1;i<=e;i++){
		scanf("%d%d%d",&a,&b,&w);
		f[a][b]=min(f[a][b],w);
		f[b][a]=min(f[b][a],w);
	}
}
void floyd(){
	for(int k=1;k<=v;k++)
		for(int i=1;i<=v;i++)
			for(int j=1;j<=v;j++)
				if(f[i][k]+f[k][j]<f[i][j])
					f[i][j]=f[i][k]+f[k][j];
/*	for(int i=0;i<=v;i++)
		printf("% 4d",i);
	for(int i=1;i<=v;i++){
		printf("\n% 4d",i);
		for(int j=1;j<=v;j++)
			printf("% 4d",f[i][j]);
	}*/
}
void solve(){
	for(int i=n-1;i>=0;i--)
		for(int j=0;j<=m;j++)
			for(int w=0;w<2;w++){
				dp[w][i][j]=dp[0][i+1][j]+f[c[w][i]][c[0][i+1]];
				dp[2][i][j]+={k[i],1-k[i]}[w]*dp[w][i][j];
//				printf("\n%d %d %d",c[w][i],c[0][i+1],f[c[w][i]][c[0][i+1]]);
				if(j){
					dp[w][i][j]=min(dp[w][i][j],
					(k[i+1])*(dp[1][i+1][j-1]+f[c[w][i]][c[1][i+1]])+
					(1-k[i+1])*(dp[0][i+1][j-1]+f[c[w][i]][c[0][i+1]]));

				}
//				printf("%d %d %d %lf\n",w,i,j,dp[w][i][j]);
			}
/*	for(int i=0;i<=n;i++)
		printf("%lf ",dp[0][i][0]);
	puts("");*/
	tmp=inf;
	for(int i=0;i<=m;i++)
		tmp=dp[0][0][i];
	printf("%.2lf\n",tmp);
}
int main(){
	read();
	floyd();
	solve();
}
