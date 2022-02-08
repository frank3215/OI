#include <bits/stdc++.h>
using namespace std;

string s[MX];

string pput(string c, int n) {
	string s;
	for (int i = 0; i < n; ++i) s += c;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	cout << pput(' '+pput('#', n-2)+'\n', s);
}
