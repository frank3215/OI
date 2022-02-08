#include <cstdio>
int l,m,n,d[100000];
bool check(int M){
	int t=0,tot=0;
	for(int i=0;i<n;i++){
		if(d[i]-t<M || l-d[i]<M) tot++;
		else t=d[i];
	}
	return tot<=m;
}
int main(){
	scanf("%d%d%d",&l,&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",d+i);
	int L=0,R=l,M;
	while(L<R){
		M=L+R+1>>1;
		if(check(M)) L=M;
		else R=M-1;
	}
	printf("%d\n",L);
}
