#include <bits/stdc++.h>
using namespace std;

void gen() {
	FILE *fout = fopen("input", "w");
	int n = 10000;
	fprintf(fout, "%d\n", n);
	for (int i = 0; i < n; ++i) {
		int l = 10;
		for (int j = 0; j < l; ++j) {
			fprintf(fout, "%c", 'a'+rand()%3);
		}
		fprintf(fout, " ");
	}
	fflush(fout);
	fclose(fout);
}

int main() {
	do {
		putchar('!');
		fflush(stdout);
		gen();
		system("./e < input > output");
		system("./std < input > answer");
	} while (!system("diff output answer"));
}
