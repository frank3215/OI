#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
int n,m; 
ll  dp[5005]; 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		dp[i]=1;
	}
	for(int i=0;i<n;++i){
		ll sum=0;
		for(int j=1;j<=m;++j){
			ll val=sum+dp[j]*1ll*(j+1);
			val%=mod;
			sum*=2;
			sum+=dp[j]*1ll*j%mod;
			sum%=mod;
			dp[j]=val;
		}
	}
	cout<<dp[m]<<'\n';
	return 0; 
}
