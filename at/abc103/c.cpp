#include <iostream>
using namespace std;
int n,a,ans=0;
int main(){
	cin>>n;
	for(;cin>>a;) ans+=a-1;
	cout<<ans<<endl;
}
