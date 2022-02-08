#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b-1); i >= a; --i)
#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define PER(i,a,b) for (int i = b; i >= a; --i)
#define F0R(i,b) FOR(i,0,b)
#define R0F(i,b) ROF(i,0,b)
#define R1P(i,b) REP(i,1,b)
#define P1R(i,b) PER(i,1,b)
using namespace std;

const int N = 2e5+10;

int n, k, a[N], s[N];

signed main() {
	cin >> n;
	a[0] = 0;
	FOR(_,0,n) {
		FOR(i,0,n) s[i] = 0;
		FOR(i,0,n) s[max(0ll,i-a[i])]++, s[min(n+1, i+a[i]+1)]--;
		FOR(i,1,n) s[i] += s[i-1];
		FOR(i,0,n) a[i] = s[i];
		FOR(i,0,n) if (a[i] != n) goto END;
		cout << _ << endl;
		break;
END:	;
	}
	//FOR(i,0,n) cout << a[i] << ' ';
}

