#include <iostream>
#include <cstdio>
#define maxn 200010
using namespace std;
int n,a[maxn],r=0,l=0,x=0,ans=0,c[maxn];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	a[0]=-1;
	for(int i=1;i<=n+1;i++){
		if(i<=n) cin>>a[i];
		if(a[i]&x||i>n){
			ans+=(i-l)*(i-l-1)/2;
			if(l<=r) ans-=(r-l)*(r-l+1)/2;
			r=i-1;
			//cout<<l<<' '<<r<<' ';
			for(;a[i]&x;x^=a[l]){
				l++;
				//printf("[%d,%d]",x,x^a[l]);
			}
		}
		x^=a[i];
		//cout<<x<<' '<<ans<<endl;
	}
	cout<<ans<<endl;
}

