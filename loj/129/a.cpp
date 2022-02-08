#include <bits/stdc++.h>
using namespace std;

const int maxn = (1<<20)+1;

int n;
char s[maxn];

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 1, j = 0, k = 1; i <= n; ++i) {
		if (s[i] < s[i-k]) {
			for (; j+k <= i; j += k) {
				printf("%d ", j+k);
			}
			i = j;
			k = 1;
		} else if (s[i] > s[i-k]) {
			k = i-j+1;
		}
	}
}
