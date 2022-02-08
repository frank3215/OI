#include <iostream>
using namespace std;
long long a,b,c,d,e,t;
long long gcd(long long b,long long d){
	if(d==0) return b;
	else return gcd(d,b%d);
}
int main(){
	cin>>t;
	while(t--){
		cin>>a>>b>>c>>d;
		e=gcd(b,d);
		//cout<<a-(a-c-1)/e*e<<' ';
		cout<<((a-(a-c-1)/e*e-b<0||a<b||d<b)?"No":"Yes")<<endl;
	}
}
