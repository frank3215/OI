#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sd(x) scanf("%d", &x)
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define debug(x) cout << #x << " = " << x << endl
#define FIO(x) \
	freopen(x ".in", "r", stdin); \
	freopen(x ".out", "w", stdout);
#define print(a,n) cout << #a << " = ";_print(a,n);
void _print(int *a, int n) { FOR(i,0,n) printf("%d%c", a[i], " \n"[i==n-1]); }
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef long long ll;

signed main() {
#ifndef ONLINE_JUDGE
	FIO("a");
#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		string s(51, 'a');
		cout << s << endl;
		FOR(i,0,n) {
			int a; sd(a);
			s[a] = (s[a]-'a'+1)%2+'a';
			cout << s << endl;
		}
	}
}

