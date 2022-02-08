#include <cstdio>
const int maxn=2e5+10;
int n,a[maxn],x,f;
long long ans;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	scanf("%d%d",&x,&f);
	for(int i=0;i<n;i++){
		if(a[i]>x)
			ans+=(a[i]-1+f)/(x+f);
	}
	printf("%I64d\n",ans*f);
}
