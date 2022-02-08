#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;
const int maxn=500010,inf=1e9+1;
int n,a[maxn],tot=0,i,b[maxn],c[maxn],tmp[2][maxn];
//a[]存数字 b[]存排序后逆序 c[]存离散化后数组
long long ans=0;
struct BIT{
	int t[maxn];
	inline int lb(int x){return x&(-x);}
	inline void add(int x){for(;x<=n;x+=lb(x)) t[x]++;}
	inline int sum(int x){int res=0;for(;x;x-=lb(x)) res+=t[x];return res;}
}t;
int cmp(int x,int y){
	return a[x]>a[y];
}
int main(){
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
		b[i]=i;
	}
	sort(b,b+n,cmp);
	for(i=0;i<n;i++){
		if(i&&a[b[i]]==a[b[i-1]]) c[b[i]]=c[b[i-1]];
		else c[b[i]]=++tot;
	}
	for(i=0;i<n;i++){
		t.add(c[i]);
		ans+=t.sum(c[i]-1);
		printf("%lld\n",ans);
	}
}
