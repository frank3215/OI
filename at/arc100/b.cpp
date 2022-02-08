#include <iostream>
const int maxn=200010;
long long b[maxn],mn,mx,ans;
long a[maxn],n,p=0,q=2,cp,cq;
using namespace std;
void f(long i){
	cp=abs(b[i]-2*b[p]);
	while(p<i && abs(b[i]-2*b[p+1])<cp)
		cp=abs(b[i]-2*b[++p]);
	mn=min(b[i]-b[p],b[p]);
	mx=max(b[i]-mn,mx);
}
void g(long i){
	if(i<q) q--;
	cq=abs(b[n-1]-2*b[q]+b[i]);
	while(q<n && abs(b[n-1]-2*b[q+1]+b[i])<cq)
		cq=abs(b[n-1]-2*b[++q]+b[i]);
	mn=min(mn,min(b[n-1]-b[q],b[q]-b[i]));
	mx=max(mx,max(b[n-1]-b[q],b[q]-b[i]));
}
int main(){
	cin>>n;
	for(long i=0;i<n;i++)
		cin>>a[i],b[i]=(i==0?a[i]:b[i-1]+a[i]);
	ans=b[n-1];
	for(long i=1;i<n-2;i++){
		mn=b[n-1],mx=0;
		f(i),g(i);
		ans=min(ans,mx-mn);
	}
	cout<<ans<<endl;
}
