#include <iostream>
using namespace std;
long double n,m;
int d;
int main(){
	cin>>n>>m>>d;
	cout<<d;
	if(d) cout<<2*(n-d)*(m-1)/n/n;
	else cout<<(m-1)/n;
}
