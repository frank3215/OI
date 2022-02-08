#include <cstdio>
#include <algorithm>
using std::max;
const int maxn=3e5+10,maxa=1.5e7+10;
int n,a[maxn],g,l,r,m,t,ans,pre[maxa],p[maxa],vis[maxa];
void calcp(){
	for(int i=2;i<maxa;i++){
	//		printf("%d %d\n",i,pre[i]);
		if(!pre[i])
			p[++p[0]]=pre[i]=i;
		for(int j=1;j<=p[0] && i*p[j]<maxa;j++){
			pre[i*p[j]]=p[j];
			if(!(i%p[j])) break;
		}
	}
}
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	calcp();
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	g=a[0];
	for(int i=1;i<n;i++)
		g=gcd(g,a[i]);
//	printf("%d\n",g);
	for(int i=0;i<n;i++){
		a[i]/=g;
		while(a[i]!=1){
			t=pre[a[i]];
			while(!(a[i]%t)) a[i]/=t;
//			printf("%d ",t);
			ans=max(ans,++vis[t]);
		}
	}
	printf("%d\n",ans?n-ans:-1);
}
