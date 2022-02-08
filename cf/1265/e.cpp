#include <bits/stdc++.h>
#define inv(x) qpow(x, P-2)
using namespace std;

const int P = 998244353;

int qpow(long long a, int x) {
	return (x?qpow(a*a%P, x/2)*(x&1?a:1):1)%P;
}

int main() {
	int n;
	cin >> n;
	long long A = 1, B = 0;
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		B = (B + (A*(100-p[i])%P*inv(100)%P)*(i+1))%P;
		A = A*p[i]%P*inv(100)%P;
	}
	B = (B + A*n)%P;
	cout << B*inv(A)%P << endl;
}
