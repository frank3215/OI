#include <algorithm>
#include <iostream>
#include <cstring>
int a[10],b[10],c[10],d[10];
int n;
long long ans;
int main() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		a[i] = i+1;
	}
	do{
		int sum = n*(n+1)/2, cur=0;
		for (int i=0; i<n; ++i) {
			if (sum == n*(n+1)/2) cur++;
			sum -= c[i] - a[i];
		}
		d[cur]++;
		ans += cur;
		int i;
		for (i = n-1; i; --i) {
			if (c[i] > c[i-1]) break;
		}
		b[i]++;
		memcpy(c,a,sizeof(a));
	}while(std::next_permutation(a,a+n));
	for (int i = 0; i < n; ++i) {
		std::cout << b[i] << ' ' << d[i] << std::endl;
	}
	std::cout << ans << std::endl;
}
