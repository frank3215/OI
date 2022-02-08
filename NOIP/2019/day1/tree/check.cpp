#include <bits/stdc++.h>
using namespace std;

void gen() {
	FILE *f = fopen("tree.in", "w");
	int t = 10;
	fprintf(f, "%d\n", t);
	while (t--) {
		int n = 9;
		fprintf(f, "%d\n", n);
		int a[n];
		for (int i = 0; i < n; ++i) a[i] = i+1;
		random_shuffle(a, a+n);
		for (int i = 0; i < n; ++i) fprintf(f, "%d%c", a[i], " \n"[i+1==n]);
		for (int i = 2; i <= n; ++i)
			fprintf(f, "%d %d\n", rand()%(i-1)+1, i);
	}
	fflush(f);
	fclose(f);
}

int main() {
	srand(time(NULL));
	int cnt = 0;
	do {
		if (cnt) cout << "OK" << endl;
		gen();
	} while (cnt++ < 10 && !system("./brute && ./tree && diff tree.out tree.ans"));
}
