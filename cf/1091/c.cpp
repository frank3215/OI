#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
int n;
std::vector<long long> v;
int main() {
	std::cin >> n;
	for (int i = 1; i*i <= n; ++i) if (!(n % i)) {
		v.push_back((long long)(n-i+2)*(n/i)/2);
		if (i * i != n) v.push_back((long long)(n-n/i+2)*i/2);
	}
	std::sort(v.begin(), v.end());
	for (int i=0; i<v.size(); ++i){
		std::cout << v[i] << ' ';
	}
	std::cout << std::endl;
}
