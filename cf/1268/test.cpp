#include <bits/stdc++.h>
using namespace std;

void a_gen() {
	FILE *F = fopen("a.in", "w");
	int n = 7, k = rand()%6+1;
	int s = rand()%9000000+1000000;
	fprintf(F, "%d %d\n%d", n, k, s);
	fflush(F);
	fclose(F);
}

void b_gen() {
	FILE *F = fopen("b.in", "w");
	int n = 9;
	fprintf(F, "%d\n", n);
	for (int i = 0, j = 9; i < n; ++i) {
		j = rand()%j+1;
		fprintf(F, "%d ", j);
	}
	fflush(F);
	fclose(F);
}

int main() {
	do {
		b_gen();
		system("./b_brute < b.in > b.ans");
		system("./b < b.in > b.out");
	} while (!system("diff b.out b.ans"));
}
