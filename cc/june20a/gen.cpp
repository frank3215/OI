#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 10;
	int seed;
	scanf("%d", &seed);
	srand(((long long)time(0)*233333+seed));
	printf("%d\n", t);
	while (t--) {
		int a[3], b[3];
		for (int i = 0; i < 3; ++i) {
			a[i] = rand()%10;
			b[i] = rand()%(10-a[i])+a[i];
			printf("%d%c", a[i]+1, " \n"[i+1==3]);
		}
		for (int i = 0; i < 3; ++i) {
			printf("%d%c", b[i]+1, " \n"[i+1==3]);
		}
	}
}
