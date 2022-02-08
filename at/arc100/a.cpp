#include <iostream>
#include <algorithm>
long n,a[200005],m;
long long ans=0;
int main(){
	using namespace std;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i],a[i]-=i;
	sort(a,a+n);
	m=a[n/2];
	for(int i=0;i<n;i++)
		ans+=abs(a[i]-m);
	cout<<ans<<endl;
}
