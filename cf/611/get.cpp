#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	string s;
	for (int i = 1; i <= n; ++i) {
		s += '?';
		string t;
		for (int j = 1; j <= i; ++j) {
			t += '?';
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			for (int k = 1; k <= c; ++k)
				cout << s << ' ' << t << endl;
		}
	}
}
