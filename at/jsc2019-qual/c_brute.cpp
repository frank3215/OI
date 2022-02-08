#include <bits/stdc++.h>
using namespace std;

int n;
char s[20];
int v[20];

void flip(int l, int r) {
	for (int i = l; i <= r; ++i)
		s[i] = (s[i]=='B')?'W':'B';
}
bool ok() {
	for (int i = 0; i < 2*n; ++i)
		if (s[i] == 'B') return false;
	return true;
}

int count(int k) {
	if (k == n) return ok();
	int res = 0, tmp;
	for (int i = 0; i < 2*n; ++i)
		if (!v[i]) tmp = i;
	v[tmp] = 1;
	for (int j = 0; j < 2*n; ++j)
		if (!v[j]) {
			v[j] = 1;
			flip(j, tmp);
			res += count(k+1);
			flip(j, tmp);
			v[j] = 0;
		}
	v[tmp] = 0;
	return res;
}

void solve() {
	scanf("%d", &n);
	scanf("%s", s);
	cout << count(0);
}

void test() {
	n = 5;
	for (int i = 0; i < (1<<(2*n)); ++i) {
		for (int j = 0; j < (2*n); ++j)
			s[j] = "BW"[(i>>j)&1];
		int tmp = count(0);
		if (tmp) {
			cout << s << ' ' << tmp << endl;
		}
	}
}

int main() {
	solve();
}
