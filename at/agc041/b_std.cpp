#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
ll ans = 0;

int main()
{
	ll n , m , v , p ;
	cin >> n >> m >> v >> p ;
	vector<ll> a(n);
	rep(i, n){
		cin >> a[i];
	}
	sort(a.rbegin(),a.rend());
	ans=n;
	ll sum=0;
	rep(i,n-p){
		sum+=(a[i+p-1]-a[i+p])*(i+1);
		if(max(a[p-1]-a[i+p],(sum+n-v-1)/(n-v))>m){
			ans=i+p;
			break;
		}
	}
	cout << ans << endl;
	return 0;
}

