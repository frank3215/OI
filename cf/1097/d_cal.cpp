#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
const int maxf = 16;
long long fact[maxf];
int pow[maxf], ftot;
/*int factor(long long n) {
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
}*/
int main() {
/*	std::cout << factor(866421317361600LL) << std::endl;
	for (int i = 0; i < ftot; ++i) {
		std::cout << fact[i] << ' ' << pow[i] << std::endl;
	}
*/
}
