#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	long long n,m,i,j,x=0,y=0,tot=0;
	char c;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++){
			scanf(" %c",&c);
			if(c=='B') x+=i,y+=j,tot++;
		}
	cout<<x/tot<<' '<<y/tot<<endl;
	return 0;
}
