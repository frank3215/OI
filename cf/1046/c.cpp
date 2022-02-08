#include <cstdio>
#include <algorithm>
const int maxn=2e5+10;
int n,a[maxn],b[maxn],c[maxn],r[maxn],mx,d,ans,cur=maxn;
int main(){
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	for(int i=1;i<=n;i++){
		scanf("%d",b+i);
		r[n-i]=b[i];
	}
	mx=a[d]+b[1];
	ans=d;
	for(int i=d-1;i;i--){
		cur=std::min(cur-1,std::upper_bound(r,r+n,mx-a[i])-r);
		if(!cur) break;
		ans--;
	}
	printf("%d\n",ans);
}
