#include <cstdio>
#include <algorithm>
#include <iostream>
const int maxn=1010;
int n,m,cur,tmp,x,y;
char s[10],ans[maxn];
int main(){
	scanf("%d",&n);
	x=y=1;
	while(x+y!=n+1){
		printf("? %d %d %d %d\n",x+1,y,n,n),fflush(stdout);
		scanf("%s",s);
		if(s[0]=='N') ans[x+(y++)-2]='R';
		else ans[(x++)+y-2]='D';
	}
	x=y=n;
	while(x+y!=n+1){
		printf("? 1 1 %d %d\n",x,y-1),fflush(stdout);
		scanf("%s",s);
		if(s[0]=='N') ans[(--x)+y-2]='D';
		else ans[x+(--y)-2]='R';
	}
	ans[2*n-2]='\0';
	printf("! %s\n",ans);
}
