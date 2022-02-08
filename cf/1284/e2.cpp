#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

typedef long double ld;

const ld pi = acos(-1.0L);

int main() {
	int n;
	cin >> n;
	ld x[n], y[n];
	F0R(i,n) cin >> x[i] >> y[i];
	long long ans = 0;
	F0R(i,n) {
		vector<ld> v;
		F0R(j,n) if (j != i)
			v.push_back(atan2(y[i]-y[j], x[i]-x[j]));
		int k = 0;
		sort(v.begin(), v.end());
		F0R(j,n-1) v.push_back(v[j]+2*pi);
		F0R(j,n-1) {
			while (k+1 < (int)v.size() && v[k+1] < v[j]+pi) ++k;
			int m = k-j;
			ans += 1ll*m*(m-1)*(m-2)/6;
		}
	}
	cout << 1ll*n*(n-1)*(n-2)*(n-3)*(n-4)/24 - ans << endl;
}
