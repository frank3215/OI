#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 1000005, P = 1000000007;
int n, h, d, s, f[N], fac[N];
int main() {
	scanf("%d%d%d", &n, &h, &d);
	fac[0]=1;
	for(int i=1; i<=n; ++i) fac[i]=(ll)fac[i-1]*i%P, s=(s+fac[i])%P;
	int now=f[0]=fac[n];
	for(int i=1; i<h; ++i){
		f[i]=(ll)s*now%P, (now+=f[i])%=P;
		if(i>=d) (now+=P-f[i-d])%=P;
	}
	printf("%d\n", now);
	return 0;
}
