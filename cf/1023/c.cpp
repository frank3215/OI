#include <iostream>
#include <string>
#include <queue>
const int maxn=2e5+10;
int main(){
	std::string s;
	int n,k,i,j,ans,tmp;
	std::cin>>n>>k>>s;
	std::deque<char> q;
	for(i=0,j=n;i<s.size();i++){
		if(!q.empty() && q.back()=='(' && s[i]==')' && j>k){
			q.pop_back(),j-=2;continue;
		}
		q.push_back(s[i]);
	}
	while(!q.empty())
		std::cout<<q.front(),q.pop_front();
}
