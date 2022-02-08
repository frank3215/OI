#include <cstdio>
#include <algorithm>
#include <iostream>
#include <stack>
const int maxn=2e5+10;
std::stack<int> s;
int n,q,i,j,cur,ok=1,a[maxn],vis[maxn];
int main(){
	scanf("%d%d",&n,&q);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
		if(!s.empty()&&s.top()<a[i]&&vis[a[i]]){
			ok=0;break;
		}
		if(!a[i]) continue;
		while(!s.empty()&&s.top()>a[i])
			vis[s.top()]=1,s.pop();
		cur=a[i];
		s.push(a[i]);
	}
	if(!ok){printf("NO\n");return 0;}
	printf("YES\n");
	for(i=q;i;i--)
		if(!vis[i]){
			a[n]=q;
			for(i=n-1;i>=0;i--)
				if(!a[i]) a[i]=a[i+1];
			break;
		}
	if(!i) for(i=0;i<
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
}
