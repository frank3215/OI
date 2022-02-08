#include <cstdio>

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",a+i);
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
			if(a[j]<a[i])
