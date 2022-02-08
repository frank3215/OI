#include <bits/stdc++.h>
using namespace std;

const int W = 10000, maxn = 1010;
int a[maxn], b[maxn], c[maxn];

void mult(vector<int> &x, int y) {
	int carry = 0;
	for (int i = 0; i < (int)x.size(); ++i) {
		x[i] = x[i]*y+carry;
		carry = x[i]/W;
		x[i] %= W;
	}
	while (carry) {
		x.push_back(carry);
		carry /= W;
	}
}

vector<int> div(const vector<int> &x, int y) {
	int carry = 0;
	vector<int> z(x.size());
	for (int i = (int)x.size()-1; ~i; --i) {
		z[i] = x[i]+carry*W;
		carry = z[i]%y;
		z[i] /= y;
	}
	while (!z.empty() && z.back() == 0) z.pop_back();
	return z;
}

bool larger(vector<int> x, vector<int> y) {
	if (x.size() > y.size()) return true;
	else if (x.size() == y.size()) {
		reverse(x.begin(), x.end());
		reverse(y.begin(), y.end());
		return x > y;
	}
	return false;
}

bool cmp(int i, int j) {
	return a[i]*b[i] < a[j]*b[j];
}

void print(vector<int> &x) {
	printf("%d", x.empty()?0:x.back());
	for (int i = (int)x.size()-2; i>=0; --i)
		printf("%04d", x[i]);
	putchar('\n');
}

void solve() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; ++i) {
		scanf("%d%d", a+i, b+i);
		c[i] = i;
	}
	sort(c+1, c+1+n, cmp);
	vector<int> x(1,1), y, ans;
	for (int i = 1; i <= n; ++i) {
		mult(x, a[c[i-1]]);
		y = div(x, b[c[i]]);
		if (larger(y, ans)) ans = y;
	}
	print(ans);
}

void test() {
	vector<int> x(2, 100), y;
	print(x);
	mult(x, 111);
	print(x);
	print(y=div(x, 1000));
}

int main() {
	solve();
}
