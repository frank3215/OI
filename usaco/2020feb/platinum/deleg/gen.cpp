#include <bits/stdc++.h>
using namespace std;

const int N = 10;

int main() {
	int n = rand()%N+1;
	printf("%d\n", n);
	for (int i = 2; i <= n; ++i) {
		printf("%d %d\n", i, rand()%(i-1)+1);
	}
}
