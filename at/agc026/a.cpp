#include <iostream>
using namespace std;
int a,b=0,c=0,n,ans=0;
int main(){
	cin>>n;
	while(n--){
		cin>>a;c++;
		if(b!=a){ans+=c/2;c=0;}
		b=a;
	}
	cout<<ans+c/2;
}
