//Uva 12345
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define maxn 50009
using namespace std;
struct node{
	int l,r,x,p;
}a[maxn];
struct nod{
	int x,y,o;
}d[maxn];
int i,j,k,l,t,n,m,ans,now,kuai[maxn],da,last[maxn],tot,num,r,
shu[1000007],b[maxn],ans1[maxn];
bool bz[maxn];
char s[10];
bool cmp(node x,node y){
	if(kuai[x.l]==kuai[y.l]){
		if(kuai[x.r]==kuai[y.r]){
			return x.x<y.x;
		}
		else return x.r<y.r;
	}
	else return x.l<y.l;
}
void update(int x){
	if(bz[x]){
		shu[b[x]]--;
		ans-=(shu[b[x]]==0);
	}
	else{
		shu[b[x]]++;
		ans+=(shu[b[x]]==1);
	}
	bz[x]^=1;
}
void change(int x,int y){
	if(bz[x]){
		update(x);
		b[x]=y;
		update(x);
	}
}
int main(){
	scanf{""}
	return 0;
}