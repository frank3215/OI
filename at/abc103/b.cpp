#include <iostream>
#include <string>
using namespace std;
string s,t;
int b,a=0;
int main(){
	cin>>s>>t;
	for(int i=0;i<s.size();i++){
		b=1;
		for(int j=0;j<s.size();j++) b&=s[(i+j)%s.size()]==t[j];
		a|=b;
	}
	cout<<(a?"Yes\n":"No\n");
}
