#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int main() {
	cin >> n >> k;
	cin >> s;
	bool big = 0;
	for (int i = k; i < n; ++i) {
		if (s[i] > s[i%k]) big = 1;
		if (s[i] < s[i%k]) break;
	}
	for (int i = k-1, j = big; ~i; --i) {
		s[i] += j;
		j = (s[i]-'0')/10;
		s[i] = s[i]-10*j;
	}
	printf("%d\n", (int)s.size());
	for (int i = 0; i < n; ++i)
		putchar(s[i%k]);
}
