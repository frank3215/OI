//What if there is one clue that is not true?
#include <algorithm>
#include <iostream>
int main() {
	int n,y,x;
	long long sumx=0,sumy=0;
	std::cin >> n;
	for (int i = 0; i < 2 * n; ++i) {
		std::cin >> x >> y;
		sumx += x;
		sumy += y;
	}
	std::cout << sumx/n << ' ' << sumy/n << std::endl;
	return -0;
}

