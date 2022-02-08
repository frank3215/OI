#include <cstdio>
const int maxn=1e5+10;
long long n,m,g;
char s[maxn],t[maxn];
long long gcd(long long n,long long m){return m?gcd(m,n%m):n;}
int main(){
	scanf("%lld%lld%s%s",&n,&m,s,t);
	g=gcd(n,m);
	for(int i=0;i<g;i++)
		if(s[i*n/g]!=t[i*m/g])
			return puts("-1"),0;
	printf("%lld\n",n*m/g);
}
