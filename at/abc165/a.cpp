#include <bits/stdc++.h>
using namespace std;

int n, l, r;

int main() {
	scanf("%d%d%d", &n, &l, &r);
	--l;
	puts(l/n==r/n?"NG":"OK");
}
