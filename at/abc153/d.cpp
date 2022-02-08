#include <bits/stdc++.h>
using namespace std;

long long solve(long long h) {
	return h==1?1:1+2*solve(h/2);
}

int main() {
	long long h;
	cin >> h;
	cout << solve(h) << endl;
	return 0;
}
