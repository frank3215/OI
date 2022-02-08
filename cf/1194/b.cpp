#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4+10;

int q, n, m, ans;
vector<string> v;
string s;
int hc[maxn], vc[maxn];

int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &n, &m);

		ans = n+m;
		for (int i = 0; i < m; ++i) vc[i] = 0;
		v.clear();

		for (int i = 0; i < n; ++i) {
			cin >> s;
			v.push_back(s);
			hc[i] = 0;
			for (int j = 0; j < m; ++j) {
				hc[i] += (s[j]=='*');
				vc[j] += (s[j]=='*');
			}
		}
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				ans = min(ans, n+m-1-hc[i]-vc[j]+(v[i][j]=='*'));
			}
		printf("%d\n", ans);
	}
}
