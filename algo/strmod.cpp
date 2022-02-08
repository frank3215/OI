//wtf?????? 编译后体积过大
#include <cstdio>
#include <cstring>
typedef long long ll;
const ll md[2]={100000037,100000007},mx=1e6+10,r=53;
int p[2][mx]={{1},{1}},m,n,i,j,ans=0;
char a[mx],b[mx];
ll ma[2]={},mb[2]={};
inline int ci(char c){
	if('A'<=c&&c<='Z') return c-'&';
	if('a'<=c&&c<='z') return c-'`';
	return 0;
}
int main(){
	//printf("%d %d\n",md[0],md[1]);
	for(i=0;i<m;i++)
		for(j=0;j<2;j++)
			mb[j]=(mb[j]+b[i]*p[j][i])%md[j],
			ma[j]=(ma[j]+a[i]*p[j][i])%md[j];
	for(i=m;i<=n;i++){
		ans+=(ma[0]==mb[0]&&ma[1]==mb[1]);
		//printf("%d %lld %lld %lld %lld %d\n",a[i],ma[0],mb[0],ma[1],mb[1],ans);
		if(!a[i]) break;
		for(j=0;j<2;j++)
			ma[j]=(ma[j]-a[i-m]*p[j][i-m]+a[i]*p[j][i]+r*md[j])%md[j],
			mb[j]=(mb[j]*r)%md[j];
	}
	printf("%d\n",ans);
}