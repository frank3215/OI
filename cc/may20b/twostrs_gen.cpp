#include <bits/stdc++.h>
using namespace std;

void gen() {
	int n = 100, l = 100, s = 26, mx = 26;
	char a[l+1] = {}, b[l+1] = {};
	for (int i = 0; i < l; ++i) {
		a[i] = 'a'+rand()%s;
		b[i] = 'a'+rand()%s;
	}
	cout << a << endl << b << endl;
	cout << n << endl;
	for (int i = 0; i < n; ++i) {
		int len = rand()%mx+1;
		for (int j = 0; j < len; ++j) {
			cout << (char)('a'+rand()%s);
		}
		cout << ' ' << (rand()%100000+1) << endl;
	}
}

int main() {
	srand(time(NULL));
	int t = 10;
	printf("%d\n", t);
	while (t--) gen();
}
