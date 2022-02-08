#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int INF=1e9,maxx=(1<<23);
int T,n,x,cnt[30],sum[30],ans,h[5][30],vis[maxx],a[30],b[30];
int pos[37];
inline int lb(int x){return x&-x;}
inline int card(int x){return a[pos[lb(x)%37]];}
void init(){
	for(int i=0;i<23;i++)
		pos[(1<<i)%37]=i;
}
int dfs(int cur){
	if(!cur || vis[cur]) return vis[cur];
	for(int i=0;i<n;i++)
		
}
int main() {
	init();
    scanf("%d %d",&T,&n);
    while (T--) {
        memset(cnt,0,sizeof(cnt));
		memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            scanf("%d %d",&a[i],b+i);
            if(a[i]==1) a[i]=14;
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			int A=a[i],C=++cnt[A];
			t[C]++;
			h[C][A]=h[C][0];
			h[C][0]=a[i]=A;
		}
		for(int i=0;i<=20;i++)
			sum[i]=(i?sum[i-1]:0)+cnt[i];
        printf("%d\n",dfs((1<<n)-1));
    }
    return 0;
}
