#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sd(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(x) scanf("%s", x)
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
#define print(a,n) cout << #a << " = ";FOR(_,0,n) printf("%d%c", a, " \n"[_==n-1])
void _print(int *a, int n) { }
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int N = 1e6+10, P = 1e9+7;

int n;
int dis[N], nxt0[N], nxt1[N], nxt[N], dp[N];
char s[N];

signed main() {
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	ss(s+1);
	n = strlen(s+1);
	int l = 1, r = n;
	while (s[l] == '0') l++;
	while (s[r] == '0') r--;
	if (l == n+1) {
		printf("%d\n", n);
		return 0;
	}
	FOR(i,l,r+1) {
		dis[i] = s[i]=='1'?0:dis[i-1]+1;
	}
	ROF(i,l,r+1) {
		nxt1[i] = nxt[0];
		nxt0[i] = nxt[dis[i]+1];
		nxt[dis[i]] = i;
	}
	dp[l] = 1;
	int ans = 0;
	FOR(i,l,r+1) {
		if (nxt0[i]) (dp[nxt0[i]] += dp[i]) %= P;
		if (nxt1[i]) (dp[nxt1[i]] += dp[i]) %= P;
		if (s[i] == '1') ans = (ans+dp[i])%P;
	}
	printf("%lld\n", (ll)ans*(n-r+1)%P*l%P);
}
