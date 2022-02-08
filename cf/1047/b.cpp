#include <cstdio>
#include <algorithm>
using std::max;
int main(){
	int x,y,n,ans=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d%d",&x,&y);
		ans=max(ans,x+y);
	}
	printf("%d\n",ans);
}
