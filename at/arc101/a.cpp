#include <cstdio>
#include <cstdlib>
#include <algorithm>
using std::abs;
using std::min;
int main(){
	int n,k,a[100010],mn=1e9;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=k-1;i<n;i++){
		mn = std::min(mn,min(abs(a[i]),abs(a[i-k+1]))+a[i]-a[i-k+1]);
	}
	printf("%d\n",mn);
}
