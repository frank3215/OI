#include <bits/stdc++.h>
using namespace std;

const int n = 1000000;

int main() {
	int k, x;
	cin >> k >> x;
	for (int i = max(-n, x-k+1); i <= min(n, x+k-1); ++i)
		cout << i << ' ';
}
