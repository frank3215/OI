#include <cstdio>
#include <cstring>
#define mm 1000010
int next[mm],i,j,n,m,ans=0;
char b[mm],a[mm];
void init(){
	for(i=0,j=-2;i<=n;)
		for(next[i++]=++j;j>=0&&b[j+1]^b[i];j=next[j]);
}
void search(){
	for(i=1,j=0;i<=m;i++){
		for(;a[i]^b[j+1]&&j>=0;j=next[j]);
		if(++j==n) ans++;//printf("%d\n",i-j+1);
	}
}
int main(){
	scanf("%s%s",a+1,b+1);
	n=strlen(b+1);
	m=strlen(a+1);
	init();
	search();
	/*for(i=1;i<=n;i++)
		printf("%d ",next[i]);
	printf("\n");*/
	printf("%d\n",ans);
}

