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
	//freopen(x ".out", "w", stdout);
#define print(a,n) cout << #a << " = ";FOR(_,0,n) printf("%d%c", a, " \n"[_==n-1])
void _print(int *a, int n) { }
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

const int MAXN = 1e6+10, ALP = 26;

int n;
char s[MAXN];
int len[MAXN], ch[MAXN][ALP], fail[MAXN], tot;
int cnt[MAXN];

int getFail(int u, int i) {
	while (s[i] != s[i-len[u]-1]) u = fail[u];
	return u;
}

void solve() {
	fail[0] = 1;
	len[1] = -1;
	tot = 1;
	int u = 0;
	FOR(i,1,n+1) {
		u = getFail(u, i);
		int &nxt = ch[u][s[i]-'a'];
		if (!nxt) {
			++tot;
			len[tot] = len[u] + 2;
			fail[tot] = ch[getFail(fail[u],i)][s[i]-'a'];
			cnt[tot] = cnt[fail[tot]]+1;
			nxt = tot;
		}
		u = nxt;
		printf("%d ", cnt[u]);
		s[i+1] = (s[i+1]-97+cnt[u])%26+97;
	}
}

signed main() {
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	scanf("%s", s+1);
	n = strlen(s+1);
	solve();
}
