#include <cstdio>
const int MAX=50001;
int l,n,m,max,d[MAX],temp=0;
bool check (int k) {
	int lst=0,cnt=0;
	for (int i=0;i<=n;i++)
		if (d[i]-lst<k) cnt++;
		else lst=d[i];
	return cnt<=m;
}
int main(){
	scanf("%d%d%d",&l,&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&d[i]);
	}
	d[n]=l;
	int a=0,b=l,c;
	while(a<=b){
		c=(a+b)/2;
		if(check(c)) a=c+1;
		else b=c-1;
	}
	printf("%d\n",b);
	return 0;
}
