//Brute
#include <cstdio>
const long long MOD=1e9+7;
const int maxn=1e2+10;
int a[maxn],n,f[maxn][maxn],fact[maxn],tcaf[maxn],suf[maxn];
/*void add(int l,int r,int k){
	for(int i=l;i<r;i++)
		ans[i][l][r]+=k;
}*/
/*void add(int l,int r,int k,int L,int R){
	for(int i=L;i<R;i++)
		ans[i][l][r]+=k*ans[i][L][R]%MOD;
}*/
long long calc(int l,int r){
	if(l==r) return 0;
	if(r-l==1) return a[l];
	if(!f[l][r]){
//		f[l][r]=(suf[l]-suf[r])*(long long)fact[r-l]%MOD;
		for(int i=l;i<r;i++){
/*			add(l,r,fact[r-l-1]);
			add(l,r,tcaf[i-l]*(long long)fact[r-l-1]%MOD,l,i);
			add(l,r,tcaf[r-i-1]*(long long)fact[r-l-1]%MOD,i+1,r);*/
			f[l][r]=(f[l][r]+(suf[l]-suf[r]+tcaf[i-l]*calc(l,i)+tcaf[r-i-1]*calc(i+1,r))%MOD*fact[r-l-1])%MOD;
		}
	}
/*	for(int i=0;i<n;i++)
		printf("%d ",ans[i][l][r]);
	printf("\n%d %d\n",l,r);*/
	return f[l][r];
}
long long inv(long long x){
	if(x==1) return 1;
	else return (MOD-MOD/x)*inv(MOD%x)%MOD;
}
int main(){
	scanf("%d",&n);
	fact[0]=1;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		fact[i+1]=fact[i]*(long long)(i+1)%MOD;
	}
	tcaf[n]=inv(fact[n]);
	for(int i=n-1;~i;i--){
		tcaf[i]=(tcaf[i+1]*(long long)(i+1))%MOD;
		suf[i]=suf[i+1]+a[i];
	}
	printf("%lld\n",calc(0,n));
}
