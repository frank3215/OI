#include <bits/stdc++.h>
using namespace std;

const int N = 100;

void gen(int n, int m) {
	FILE *fin = fopen("meal.in", "w");
	fprintf(fin, "%d %d\n", n, m);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j)
			fprintf(fin, "%d%c", rand()%1000, " \n"[j+1==m]);
	}
	fflush(fin);
	fclose(fin);
}

void duipai() {
	for (int i = 0; i < N; ++i) {
		gen(4, 2);
		system("brute");
		system("meal");
		if (system("fc meal.out meal.ans")) break;
	}
}

int main() {
	gen(10, 3);
}
