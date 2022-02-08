#include <bits/stdc++.h>
using namespace std;

const char *par = "()";
const int pm[] = {1, -1};

int check(string s) {
	vector<int> v(s.size());
	int mn = 0;
	for (int i = 0, pre = 0; i < (int)s.size(); ++i) {
		v[i] = pre+pm[strchr(par, s[i])-par];
		mn = min(mn, pre=v[i]);
	}
	if (v.back() != 0) return 0;
	int res = 0;
	for (int i = 0; i < (int)v.size(); ++i)
		if (v[i] == mn) res++;
	return res;
}

int main() {
	int n;
	string s;
	cin >> n >> s;
	int ans[3] = {};
	for (int l = 0; l < n; ++l)
		for (int r = l; r < n; ++r) {
			swap(s[l], s[r]);
			int res = check(s);
			if (res > ans[0])
				ans[0] = res, ans[1] = l, ans[2] = r;
			swap(s[l], s[r]);
		}
	cout << ans[0] << endl << ans[1]+1 << ' ' << ans[2]+1 << endl;
}
