#include <cstdio>
#include <algorithm>
using std::min;
using std::max;
using std::swap;
const int maxn=1003,maxnn=1000003,maxq=300010;

int n,q,i,j,x,y,z,w,f[maxnn],t1,t2,fi,fj,
dp1[maxn][maxn],dp2[maxn][maxn],dp[maxn][maxn],up[maxn],cnt,down[maxn],
next[maxnn],head[maxn]={},tot=0,mx=0,ans[maxq],
pre[maxq],nex[maxq],val[maxq],end;
char c;
bool m[maxn][maxn];

inline int get(int x,int y){return (x-1)*n+y;}
inline void extract(int p){x=1+(p-1)/n,y=(p-1)%n+1;}
int find(int i){
	while(f[i]>0) i=f[i];
	return i;
}
inline void uion(int i,int j) {
	if((fi=find(i))==(fj=find(j))) return;
	if(f[fi]>f[fj]) swap(fi,fj);
	f[fi]-=(f[fi]==f[fj]);
	f[fj]=fi;
}
inline void add(int p){
	extract(p);
	//printf("(%d,%d)\n",x,y);
	f[p]=-1;
	if(x>1&&f[p-n]) uion(p,p-n);
	if(x<n&&f[p+n]) uion(p,p+n);
	if(y>1&&f[p-1]) uion(p,p-1);
	if(y<n&&f[p+1]) uion(p,p+1);
}

struct ask{
	int s,t,i,d;
	void scan(int j){
		int sx,sy,tx,ty;
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty),i=j,
		s=get(sx,sy),t=get(tx,ty),
		d=min(dp[sx][sy],dp[tx][ty]);
	}
	bool operator <(const ask &a) const{
		return d<a.d;
	}
}a[maxnn];

int main() {
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		for(cnt=0,j=1;j<=n;j++){
			scanf(" %c",&c);
			if((m[i][j]=(c=='#'))) cnt=up[j]=0;
			else{
				t1=(dp1[i][j]=min(dp1[i-1][j-1]+1,min(++cnt,++up[j])))-1;
				t2=(t1>>1)+(t1&1),t1>>=1;
				for(x=i-t2;x<=i-t1;x++)
					for(y=j-t2;y<=j-t1;y++)
						dp[x][y]=max(dp[x][y],t1+1);
			}
		}
	for(i=n;i;i--)
		for(cnt=0,j=n;j;j--)
			if(m[i][j]) cnt=down[j]=0;
			else{
				t1=(dp2[i][j]=min(dp2[i+1][j+1]+1,min(++cnt,++down[j])))-1;
				t2=(t1>>1)+(t1&1),t1>>=1;
				for(x=i+t1;x<=i+t2;x++)
					for(y=j+t1;y<=j+t2;y++)
						dp[x][y]=max(dp[x][y],t1+1);
			}
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			//printf("%d ",dp[i][j]),
			mx=max(mx,dp[i][j]),
			next[++tot]=head[dp[i][j]],
			head[dp[i][j]]=tot;
	scanf("%d",&q);
	for(i=1;i<=q;i++)
		a[i].scan(i),
		pre[i]=i+1,
		nex[i]=i-1;
	std::sort(a,a+q+1);
	nex[q+1]=q,a[q+1].d=mx;
	for(i=mx;i;i--){
		for(j=head[i];j;j=next[j]) add(j);
		for(j=q+1;a[j].d>=i&&j>0;j=nex[j])
			if(j<=q&&find(a[j].s)==find(a[j].t))
				ans[a[j].i]=(i<<1)-1,
				nex[pre[j]]=nex[j],
				pre[nex[j]]=pre[j];
	}
	for(i=1;i<=q;i++) printf("%d\n",ans[i]);
}