//bi= min{ | aj - ai | } (j<i) , 求sum(bi)
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;
const int inf=1e7;
int n,ans,tmp,a;
set<int> s;
set<int>::iterator si;
int main(){
	cin>>n>>a;
	ans=a;
	while(--n){
		s.insert(a);
		cin>>a;
		si=s.lower_bound(a);
		tmp=inf;
		if(si!=s.end()) tmp=min(tmp,abs(a-*si));
		if(si!=s.begin()) tmp=min(tmp,abs(a-*--si));
		ans+=tmp;
	}
	cout<<ans<<endl;
}