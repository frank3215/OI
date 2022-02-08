#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d, s1 = 0, s2 = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> d;
		s1 += d;
		s2 += d*d;
	}
	cout << (s1*s1-s2)/2 << endl;
}
