#include <cstdio>
int ret(int a,int b){
	if(a>b) return ret(b,a);
	int w[5][5]={{0,-1,1,1,-1},{0,0,-1,1,-1},{0,0,0,-1,1},{0,0,0,0,1},{0,0,0,0,0}};
	return w[a][b];
}
int main(){
	int r,n,na,nb,wa,wb,a[201],b[201];
	scanf("%d %d %d",&n,&na,&nb);
	for(int i=0;i<na;i++){
			scanf("%d ",a[i]);
			printf("%d",a[i]);
			}
	for(int i=0;i<nb;i++) scanf("%d",b[i]);
	for(int i=0;i<n;i++){
			r=ret(a[i%na],b[i%nb]);
			if(r==1) wa++;
			if(r==-1) wb++;
			}
	printf("%d %d",wa,wb);                                        
	return 0;
}
