#include <iostream>
#include <string>
int main(){
	long long f,x,y;
	std::string s,a,b,t;
	std::cin >> x >> y >> s >> t;
	if((f=s.find('*'))==std::string::npos) std::cout << ((s==t)?"YES\n":"NO\n");
	else{
		a=s.substr(0,f),b=s.substr(f+1);
		std::cout << (y>=x-1&&t.substr(0,f)==a&&t.substr(y-(x-f-1))==b?"YES\n":"NO\n");
	}
}
