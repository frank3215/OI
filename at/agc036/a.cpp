#include <bits/stdc++.h>
using namespace std;

long long s;
int a, b, c, d, t;

int main() {
	cin >> s;
	t = ceil(sqrt(s)-1e-6)+1e-6;
	a = b = t;
	c = 1;
	d = (long long)a*b - s;
	printf("0 0 %d %d %d %d", a, c, d, b);
}
