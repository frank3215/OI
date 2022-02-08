#include <cstdio>
#include <vector>
#include <iostream>
#include <string>

#define printf(...) //printf(__VA_ARGS__)

using namespace std;

vector<int> cnt;
vector<vector<int> > ch;

int ans;

void add(const string &s) {
	printf("%s\n", s.c_str());
	for (int i = 0, u = 0; i < (int) s.size(); ++i) {
		if (ch[u][s[i]-'A'] == -1) {
			ch[u][s[i]-'A'] = (int) ch.size();
			ch.push_back(vector<int>(26, -1));
			cnt.push_back(0);
		}
		u = ch[u][s[i]-'A'];
		cnt[u]++;
		printf("%d\n", u);
	}
}
int dfs(int u) {
	if (u == -1) return 0;
	printf("%d %d: %d\n", u, cnt[u], ans);
	int res = 0;
	for (int i = 0; i < 26; ++i)
		res += dfs(ch[u][i]);
	printf("  %d %d: %d\n", u, cnt[u], ans);

	cnt[u] -= res;
	if (cnt[u] >= 2) {
		cnt[u] -= 2;
		ans += 2;
		res += 2;
	}
	printf(" %d %d: %d\n", u, cnt[u], ans);
	return res;
}

void solve(int kase) {
	ch.clear();
	cnt.clear();
	cnt.push_back(0);
	ch.push_back(vector<int>(26, -1));

	cout << "Case #" << kase << ": ";

	int n;
	cin >> n;
	string s;
	for (int i = 0; i < n; ++i) {
		cin >> s;
		add(string(s.rbegin(), s.rend()));
		printf("%d: success\n", i);
	}
	ans = 0;
	dfs(0);
	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;
	for (int k = 1; k <= t; ++k) solve(k);
}
