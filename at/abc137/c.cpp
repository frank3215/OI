#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;

map<vector<int>, int> mp;

int n;
long long ans;
string s;

int main() {
	cin >> n;
	while (n--) {
		vector<int> v(26);
		cin >> s;
		for (int i = 0; i < (int)s.size(); ++i)
			v[s[i]-'a']++;
		ans += mp[v]++;
	}
	cout << ans;
}
