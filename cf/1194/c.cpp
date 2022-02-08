#include <bits/stdc++.h>
using namespace std;

int q, cnt[26];
string s, t, p;

bool solve() {
	cin >> s >> t >> p;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < p.size(); ++i) cnt[p[i]-'a']++;
	int j = 0;
	for (int i = 0; i < t.size(); ++i) {
		if (j < s.size() && t[i] == s[j]) ++j;
		else if (!(cnt[t[i]-'a']--)) return false;
	}
	return j == (int)s.size();
}

int main() {
	scanf("%d", &q);
	string s, t, p;
	while (q--) {
		puts(solve()?"YES":"NO");
	}
}
