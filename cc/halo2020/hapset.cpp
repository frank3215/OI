#include <bits/stdc++.h>
using namespace std;

const int P = 1e9+7, N = 5e5+10;
int n, l, k;
int a[N], f[N], F[N];

typedef long long ll;

int qpow(int a,int x){
	int ret=1;
	for(;x;a=(ll)a*a%P,x>>=1)if(x&1)ret=(ll)ret*a%P;
	return ret;
}
int c(int n,int k){
	if(k>n||k<0)return 0;
	else return ((ll)f[n]*F[k]%P*(ll)F[n-k]%P);
}
int main() {
	cin>>n>>l>>k;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	f[0]=1;
	for(int i=1;i<=n;++i) f[i]=(ll)i*f[i-1]%P;
	F[n]=qpow(f[n],P-2);
	for(int i=n;i>=1;--i)F[i-1]=F[i]*(ll)i%P;
	int ans = 0;
	for(int i=1,j=1;i<=n;++i){
		for(;j+1<=n&&a[j+1]-a[i]<=k;++j);
		(ans+=c(j-i,l-1))%=P;
	}
	cout << ans << endl;
}

