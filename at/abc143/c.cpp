#include <bits/stdc++.h>
using namespace std;

int n, ans = 1;
string s;

int main() {
	cin >> n >> s;
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i-1]) ans++;
	}
	cout << ans;
}
