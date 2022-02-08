#include <iostream>
#include <algorithm>
#define maxn 300010
using namespace std;
int n,m=0,e,ans=maxn;
char s[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>s;
	for(int i=0;i<n;i++)
		e+=s[i]=='E';
	ans=e-(m=s[0]=='E');
	for(int i=1;i<n;i++){
		m+=s[i]=='E';
		ans=min(ans,i+1+e-2*m);
	}
	cout<<ans<<endl;
}
