#include <iostream>
using namespace std;
int m,n,a,b,p[100010],ans=0;
int main(){
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		p[a-1]=(p[a-1]?max(p[a-1],a-b):a-b);
	}
	b=0;
	for(int i=0;i<n;i++){
		if(!p[i]) continue;
		//cout<<p[i]<<' '<<b<<endl;
		if(b<=i){
			ans++;
			b=i-p[i];
		}
		else b=min(b,i-p[i]);
	}
	cout<<ans<<endl;
}
