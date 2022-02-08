#include <iostream>
#include <algorithm>
int main() {
	int a,b,c;
	std::cin >> a >> b >> c;
	std::cout << 3 * std::min(a+1,std::min(b,c-1)) << std::endl;
}
