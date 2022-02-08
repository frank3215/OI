#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,b,a) for (int i = (b)-1; i >= a; --i)
using namespace std;

const int N = 2e5+10;

int n, cnt[2], zero;
long long ans;
char t[N];

signed main() {
	scanf("%s", t);
	n = strlen(t);
	FOR(i,0,n) cnt[t[i]-'0']++;
	for (int i = 0; i < n; ) {
		if (t[i] == '1' && t[i+1] == '1') {
			ans += cnt[0];
			i += 2;
			continue;
		}
		if (t[i] == '0') {
			++zero;
		} else {
			ans += i/2-(i-zero)/2;
			ans += cnt[0]-zero;
		}
		++i;
	}
	FOR(i,0,cnt[1]) {
		ans += i/2+1;
	}
	printf("%lld\n", ans);
}

