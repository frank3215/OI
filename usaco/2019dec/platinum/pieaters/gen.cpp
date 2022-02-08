#include <bits/stdc++.h>
using namespace std;

void gen() {
	int n = 3, m = n*(n+1)/2;
	FILE *fout = fopen("pieaters.in", "w");
	fprintf(fout, "%d %d\n", n, m);
	for (int i = 1; i <= n; ++i)
		for (int j = i; j <= n; ++j)
			fprintf(fout, "%d %d %d\n", rand()%n, i, j);
	fflush(fout);
	fclose(fout);
}

int main() {
	do {
		gen();
		system("./fuck");
		system("./pieaters");
	} while (!system("diff pieaters.out pieaters.ans"));
}
