#include <cstdio>
#define min(a,b) a>b?b:a
/* Mowing the Lawn, USACO 2011 Open
 * 有n只奶牛排成一行，第i只奶牛的能干程度为ai，现在问如何选择奶牛，使得没有连续k只奶牛同时被选，并且所选的奶牛能干程度之和最大。
 */
#define m 1000000
long long n,f[m],start=0,end=0,k,q[m],e,total=0,ans=1ll<<60,a[m];

int main(){
	scanf("%lld %lld",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		total+=a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=q[start]+a[i];
		while(start<end && f[q[i]]>f[i]) end--;
		q[++end]=f[i];
		while(start<end && q[start]<=i-k-1) start++;
	}
	/*
	k++;
	for(int i=1;i<=n;i++){
		scanf("%lld",&e);
		total+=e;
		while(start<end&&f[q[end]]>=f[i-1]) end--;
		q[++end]=i-1;
		while(q[start]<i-k) start++;
		f[i]=e+f[q[start]];
	}*/
	ans=f[n];
	for(int i=n-k;i<n;i++) ans=min(ans,f[i]);
	printf("%lld",total-ans);
}