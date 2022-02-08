#include <bits/stdc++.h>
using namespace std;

int nxt[100];

void kmp(string &a, string &b) {
	nxt[0] = -1;
	for (int i = 0, j; i < a.size(); ++i) {
		for (j = nxt[i]; j>=0 && a[j] != a[i]; j = nxt[j]);
		nxt[i+1] = ++j;
	}
	for (int i = 0; i <= a.size(); ++i)
		cout << nxt[i] << ' ';
	cout << endl;
	for (int i = 0, j = -1; i < b.size(); ++i) {
		cout << i << ' ' << j << endl;
		if (++j == (int)a.size()) j = nxt[j];
		for (; j >= 0 && a[j] != b[i]; j = nxt[j]);
	}
}

int main() {
	string a, b;
	cin >> a >> b;
	kmp(a, b);
}
