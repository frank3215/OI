#include <bits/stdc++.h>
using namespace std;

int n, vis[10];
string s;

int main() {
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		if (isdigit(s[i])) {
			vis[s[i]-'0'] = 0;
		} else {
			if (s[i] == 'R') {
				for (int i = 9; ~i; --i)
					if (!vis[i]) {
						vis[i] = 1;
						break;
					}
			} else {
				for (int i = 0; i <= 9; ++i)
					if (!vis[i]) {
						vis[i] = 1;
						break;
					}
			}
		}
	}
	for (int i = 0; i <= 9; ++i) cout << vis[i]; cout << endl;
}
