#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

int n;
ll xxj[51];

signed main() {
	scanf("%d", &n);
	FOR(i,0,n) {
		ll cur;
		scanf("%lld", &cur);
		ROF(i,0,51) {
			if ((cur>>i)&1) {
				if (!xxj[i]) {
					xxj[i] = cur;
					break;
				}
				cur ^= xxj[i];
			}
		}
	}
	ll ans = 0;
	ROF(i,0,51) {
		if (((ans>>i)&1) == 0 && xxj[i]) {
			ans ^= xxj[i];
		}
	}
	printf("%lld\n", ans);
}

