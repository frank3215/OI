#include <iostream>
#include <algorithm>
long long a,b,c,d;
int main(){
	std::cin >> a >> b;
	c=std::max(1LL,b-a);
	d=(b-1)/2;
	std::cout << std::max(0LL,std::min(a,d)-c+1);
}
