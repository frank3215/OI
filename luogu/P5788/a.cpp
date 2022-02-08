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

const int N = 3e6+10;

int n, a[N], ans[N];
int st[N], top;

signed main() {
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	scanf("%d", &n);
	FOR(i,1,n+1) {
		scanf("%d", a+i);
	}
	ROF(i,1,n+1) {
		while (top && a[st[top]] <= a[i]) --top;
		ans[i] = top?st[top]:0;
		st[++top] = i;
	}
	FOR(i,1,n+1) {
		printf("%d ", ans[i]);
	}
}

