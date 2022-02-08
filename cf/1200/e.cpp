#include <bits/stdc++.h>
using namespace std;

int n;
string a, b;

void merge(string &a, string &b) {
	vector<int> nxt(1,-1);
	for (int i = 0, j; i < b.size(); ++i) {
		for (j = nxt[i]; j>=0 && b[j] != b[i]; j = nxt[j]);
		nxt.push_back(++j);
	}
	int j = 0;
	for (int i = max(0, (int)a.size()-(int)b.size()); i < a.size(); ++i, ++j) {
		if (j == (int)b.size()) j = nxt[j];
		for (; j >= 0 && b[j] != a[i]; j = nxt[j]);
	}
	a += b.substr(j);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> b;
		merge(a, b);
	}
	cout << a << "\n";
}
