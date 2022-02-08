#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> nxt;
string s[100010];

void merge(int l, int r) {
	if (r-l < 2) return;
	int m = (l+r)>>1;
	merge(l, m);
	merge(m, r);
//	cout << l << ' ' << m << ' ' << r << endl;
//	cout << l << ' ' << s[l] << endl;
//	cout << m << ' ' << s[m] << endl;
	string &a = s[l], &b = s[m];
	nxt = vector<int>(1, -1);
	for (int i = 0, j; i < b.size(); ++i) {
		for (j = nxt[i]; j>=0 && b[j] != b[i]; j = nxt[j]);
		nxt.push_back(++j);
	}
	int j = 0;
	for (int i = 0; i < a.size(); ++i, ++j) {
		if (j == (int)b.size()) j = nxt[j];
		for (; j >= 0 && b[j] != a[i]; j = nxt[j]);
	}
//	cout << j << endl;
	for (int i = j; i < b.size(); ++i) {
		a += b[i];
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	merge(0, n);
	cout << s[0] << "\n";
}
