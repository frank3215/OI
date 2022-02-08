#include <bits/stdc++.h>
using namespace std;

void RANDOM(FILE *f) {
	int l = rand()%100, r = rand()%100;
	if (l > r) swap(l, r);
		fprintf(f, "%d %d ", l, r);
}

void gen() {
	FILE *f = fopen("input", "w");
	int n = 100;
	fprintf(f, "%d\n", n);
	for (int i = 1; i <= n; ++i) {
		RANDOM(f);
		RANDOM(f); fprintf(f, "\n");
	}
	fflush(f);
	fclose(f);
}

int main() {
	srand(time(NULL));
	do {
		puts("GEN");
		gen();
		puts("TEST");
	} while (!system("./d_ans < input > output"));
}
