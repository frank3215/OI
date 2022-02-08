#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", a+i);
			b[a[i]]++;
		}
		mu[1] = 1;
		for (int i = 2; i < N; ++i) {
			if (!nop[i]) {
				mu[i] = -1;
				for (int j = 2*i; j <= N; j += 2*i) {
					nop[j] = 1;
					if ((j/i)%i) mu[j] = -mu[j]
					else mu[j] = 0;
				}
			}
		}
		for (int i = 2; i < N; ++i) {
			for (int j = i; j <= N; j += i) {
			   	if ((j/i)%i) {
					cur1 += b[j];
				} else {
					cur2 += b[j];
				}
			}
		}
	}
}
