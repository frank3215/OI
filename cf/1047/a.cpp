#include <cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int a=1,b=(n%3?2:1),c=n-a-b;
	printf("%d %d %d\n",a,b,c);
}
