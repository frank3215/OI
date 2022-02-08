#include <bits/stdc++.h>
const int maxn = 5e5+10;
int n, k;
unsigned s[maxn], a[maxn];
long long ans, res;
unsigned RAND() {
	return (long long)rand()*(RAND_MAX)+(long long)rand();
}
void solve() {
	std::priority_queue<unsigned> q;
	for (int i = 1; i <= n; ++i) {
		s[i] = s[i-1]^a[i];
		for (int j = 0; j < i; ++j) {
			q.push(s[i]^s[j]);
		}
	}
	ans = 0;
	while (k--) {
		unsigned x = q.top();q.pop();
		ans += x;
	}
}
void gen() {
	FILE *fout = fopen("xor.in", "w");
	fprintf(fout, "%d %d\n", n, k);
	for (int i = 1; i <= n; ++i) {
		fprintf(fout, "%u\n", a[i] = RAND());
	}
	fclose(fout);
}
int main() {
	for (int i = 0;; ++i) {
		n = 100, k = 100;
		gen();
		solve();
		system("./xor");
		FILE *fin = fopen("xor.out", "r");
		fscanf(fin, "%lld", &res);
		if (res != ans) {
			printf("WA! %lld\n", ans);
			break;
		}
		else {
			puts("AC");
		}
		fclose(fin);
	}
}
