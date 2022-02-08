#include <bits/stdc++.h>
using namespace std;

void gen() {
	FILE *fout = fopen("snowcow.in", "w");
	int n = 999, q = n;
	fprintf(fout, "%d %d\n", n, q);
	for (int i = 2; i <= n; ++i) {
		fprintf(fout, "%d %d\n", rand()%(i-1)+1, i);
	}
	for (int i = 1; i <= n; ++i) {
		int op = rand()%2+1, x = rand()%n+1;
		fprintf(fout, "%d %d", op, x);
		if (op == 1) fprintf(fout, " %d", rand()%n+1);
		fprintf(fout, "\n");
	}
}

int main() {
	do {
		gen();
	} while (!system("./snowcow"));
}
