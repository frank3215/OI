#include <bits/stdc++.h>
using namespace std;

void gen() {
	int n = 1000, k = 2, q = 200000;
	FILE *f = fopen("nondec.in", "w");
	fprintf(f, "%d %d\n", n, k);
	for (int i = 1; i <= n; ++i)
		fprintf(f, "%d%c", rand()%k+1, " \n"[i==n]);
	fprintf(f, "%d\n", q);
	for (int j = 1; j <= q; ++j) {
		int l = rand()%n+1, r = rand()%n+1;
		if (l > r) swap(l, r);
		fprintf(f, "%d %d\n", l, r);
	}
	fflush(f);
	fclose(f);
}

int main() {
	int cnt = 0;
	do {
		gen();
		system("./nondec");
		system("./brute");
		cout << "AC\n";
		cnt++;
	} while (!system("diff nondec.out nondec.ans") && cnt <= 10);
}
