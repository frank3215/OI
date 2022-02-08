#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 85;
const int W = 100000000;
signed n, m, a[maxn][maxn];

struct big{
	vector<int> v;
	big(int n=0) : v(n) {}
	int operator [](int x) const { return (x>=v.size()||x<0)?0:v[x]; }
	void print() const{
//		cout << v.size() << endl;
		printf("%d", v.empty()?0:v.back());
		for (int i = (int)v.size()-2; i>=0; --i)
			printf("%08lld", v[i]);
		putchar('\n');
		fflush(stdout);
	}
	big& operator =(const big &x) {
		v = x.v;
		return *this;
	}
	big& operator +=(const big &x) {
		v.resize(max(v.size(), x.v.size())+1);
		int car = 0;
		for (int i = 0; i < v.size(); ++i) {
			v[i] += x[i]+car;
			car = v[i]/W;
			v[i] %= W;
		}
		while ((!v.empty()) && v.back() == 0) v.pop_back();
		return *this;
	}
	big operator +(const big &x) {
		big y = *this;
		y += x;
		return y;
	}
	big &operator *= (int x) {
		int car = 0;
		for (int i = 0; i < v.size(); ++i) {
			v[i] = v[i]*x+car;
			car = v[i]/W;
			v[i] %= W;
		}
		while (car) {
			v.push_back(car);
			car /= W;
		}
		return *this;
	}
	big operator * (int x) const {
		big y = *this;
		return y *= x;
	}
	bool operator < (const big &x) const {
		if (v.size() < x.v.size()) return true;
		if (v.size() == x.v.size()) {
			vector<int> y = v, z = x.v;
			reverse(y.begin(), y.end());
			reverse(z.begin(), z.end());
			return y < z;
		}
		return false;
	}
}f[maxn][maxn], pow2[maxn], ans;

signed main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &a[i][j]);
		}
	pow2[0].v.push_back(1);
	for (int i = 1; i <= m; ++i) {
		pow2[i] = pow2[i-1]*2;
	}
	for (int i = 1; i <= n; ++i) {
		for (int r = 1; r <= m; ++r)
			for (int l = r; l; --l) {
				f[l][r] = max(pow2[m-(r-l)]*a[i][l] + f[l+1][r], pow2[m-(r-l)]*a[i][r]+f[l][r-1]);
			}
		ans = ans+f[1][m];
	}
	ans.print();
}
