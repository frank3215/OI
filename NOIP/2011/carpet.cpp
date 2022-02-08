#include <cstdio>
#define MAX 10001
bool cover(int a, int b, int g, int k, int x, int y)
{
	return (a<=x&&(a+g)>=x&&b<=y&&(b+k)>=y);
}
int main()
{
	int n,a[MAX],b[MAX],g[MAX],k[MAX],x,y,i;
	scanf("%d",&n);
	for(i=0;i<n;i++) scanf("%d %d %d %d",&a[i],&b[i],&g[i],&k[i]);
	scanf("%d %d",&x,&y);
	while(i>-1){
		if(cover(a[i],b[i],g[i],k[i],x,y)) break;
		i--;
	}
	printf("%d\n",(i>0?i+1:i));
}