#include <bits/stdc++.h>
using namespace std;

const double pi = acos(-1), eps = 1e-4;

double a, b, c, t;

int main() {
	cin >> a >> b;
	a += eps;
	b += eps;
	c = sqrt(a*a+b*b);
	t = acos(a/c);
	if (b < 0) t = 2*pi-t;
	t = t/pi*180;
	printf("%.2lf\n%.2lf\n", c, t);
}
