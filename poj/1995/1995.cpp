#include <cstdio>
int z,m,h,a,b;
int pow(long long a,int b,int p)
{
	return (b?(pow(a*a%p,b/2,p)*(b&1?a:1)):1)%p;
}
int main()
{
	scanf("%d",&z);
	while (z--)
	{
		int ans=0;
		scanf("%d%d",&m,&h);
		while (h--) {
			scanf("%d%d",&a,&b);
			ans=(ans+pow(a,b,m))%m;
		}
		printf("%d\n",ans);
	}
}
