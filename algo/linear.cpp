#include <cstdio>
int n,g[100],y[100],a[100],x[100],c;
int gcd(int x,int y){
	return (y?gcd(y,x%y):x);
}

int main(){
	scanf("%d",&n);
	g[0]=0;
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		g[i]=gcd(g[i-1],a[i]);
	}
	scanf("%d",&c);
	if (c % g[n]==0){
		y[n]=c/g[n];
		for (int i=n;i>1;i--)
			extended_gcd(g[i-1],a[i],g[i]*y[i],y[i-1],x[i]);
			x[1]=y[1];
			for(int i=1;i<=n;i++) printf("%d ",x[i]);
	}
	return 0;
}