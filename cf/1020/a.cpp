#include <cstdio>
#include <cstdlib>
int n,h,a,b,k,fa,ta,fb,tb,ans;
int main(){
	using std::abs;
	scanf("%d%d%d%d%d",&n,&h,&a,&b,&k);
	while(k--){
		scanf("%d%d%d%d",&ta,&fa,&tb,&fb);
		if (ta==tb) ans=abs(fa-fb); //就漏写了这一句！！！
		else if(fb>b) ans=abs(fa-b)+abs(fb-b);
		else if(fb<a) ans=abs(fa-a)+abs(fb-a);
		else ans=abs(fa-fb);
		ans+=abs(ta-tb);
		printf("%d\n",ans);
	}
}
