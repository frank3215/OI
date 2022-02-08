#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 200000;
	for (int i = 1; i < n; ++i) printf("%d ", i); putchar('\n');
	int div = rand()%n+1;
	for (int i = 1; i <= n; ++i) printf("%d ", i <= div); putchar('\n');
}
