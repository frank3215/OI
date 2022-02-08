#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
const int maxf = 3e4, maxk = 1e4;
const int P = 1e9+7;
const int sgn[] = {1, -1};
int n;
long long k, fact[maxf];
int pow[maxf], ftot;
//std::vector<int> factors;
int facts[maxf], siz, nums[maxf],hasf[16];
std::vector<int> has[maxf];
int val[maxk][maxf];
int inv[maxf] = {0, 1};
int factor(long long n) {
	long long res = 1;
	for (long long i = 2; n != 1;) {
		if (n % i == 0) {
			std::cout << i << std::endl;
			fact[ftot] = i;
			for (; n % i == 0; n /= i) {
				++pow[ftot];
			}
			res *= pow[ftot] + 1;
			++ftot;
		}
		if (++i > n) break;
		if (i * i > n) i = n;
	}
	return res;
}
void get(int cur, long long prod, int num) {
	if (cur == ftot) {
		facts[siz] = prod;
		nums[siz] = num;
		for (int i = 0; i < ftot; ++i) {
			has[siz].push_back(sgn[has[i] % 2] * fact[i]);
		}
		++siz;
		return;
	}
	for (int i = 0; i <= pow[cur]; ++i) {
		hasf[cur] = i;
		get(cur + 1, prod, num * (i + 1));
		prod *= fact[i];
	}
}
int main() {
	scanf("%d", &n);
	factor(n);
/*
	for (long long f = 1; f * f <= n; ++f) {
		if (n % f == 0) {
			factors.push_back(f);
			if (f * f != n) factors.push_back(n/f);
		}
	}
	len = factors.size();
	std::sort(factors.begin(), factors.end());
*/
	get(0,1,1);
	for (int i = 2; i <= siz; ++i) {
		inv[i] = P - ((long long)(P/i)*inv[P%i])%P;
	}
	for (int i = 0; i < k; ++i) {
		for (int j = 0; j < siz; ++j) {

		}
	}
}
