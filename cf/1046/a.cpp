#include <cstdio>
#include <algorithm>
const int maxn=1e5+10;
int r[maxn],x[maxn],q[maxn],l[maxn];
using std::sort;
using std::min;
bool cmp(int i,int j){
	return q[i] < q[j];
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",x+i,r+i,q+i);
		l[i]=i;
	}
	sort(l,l+n,cmp);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=min(n-1,i+k);j++)
			
}
