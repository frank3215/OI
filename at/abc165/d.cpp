#include <bits/stdc++.h>
using namespace std;

long long a, b, n;

int main() {
	scanf("%lld%lld%lld", &a, &b, &n);
	printf("%lld", a*min(b-1,n)/b);
}
