#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
const int maxn=1e5+2000,maxt=2000;
int n,t,k,i,j,l,r,L,R,m,ans,tmp,x,y,a[maxn],b[maxn],times[maxn],mx[maxt][maxt],mode[maxt][maxt],cur,num[maxn],tot;
std::vector<int> v[maxn];
inline int rank(int a){
	return std::lower_bound(b+1,b+m+1,a)-b;
}
inline int occur(int a,int L,int R){
	return upper_bound(v[a].begin(),v[a].end(),R)-lower_bound(v[a].begin(),v[a].end(),L);
}
int main(){
	scanf("%d",&n);
	t=int(sqrt(n)+1);
	for(i=1;i<=n;i++)
		scanf("%d",a+i),
		b[i]=a[i];
	std::sort(b+1,b+n+1);
	m=std::unique(b+1,b+n+1)-b-1;
	for(i=1;i<=n;i++)
		v[a[i]=rank(a[i])].push_back(i);
	for(i=1;i<=n/t;i++){
		memset(times,0,sizeof(times));
		for(j=i+1;j<=n/t;j++)
			for(k=(j-1)*t;k<j*t;k++)
				if(++times[a[k]]>mx[i][j]||(times[a[k]]==mx[i][j]&&a[k]<mode[i][j]))
					mx[i][j]=times[a[k]],mode[i][j]=a[k];
	}
	for(j=0;j<n;j++){
		scanf("%d%d",&l,&r);
		x=l/t+1,y=r/t,tot=0;
		cur=mode[l/t+1][r/t],
		ans=mx[l/t+1][r/t];
		L=std::min((l/t+1)*t-1,r);
		R=std::max((r/t)*t+1,l);
		//printf("%d %d %d %d\n",l,L,R,r);
		for(i=l;i<=L;i++) num[tot++]=a[i];
		for(i=R;i<=r;i++) num[tot++]=a[i];
		for(i=0;i<tot;i++)
			if((tmp=occur(num[i],l,r))>cur||(tmp==cur&&num[i]<ans))
				cur=tmp,ans=num[i];
		printf("%d\n",b[ans]);
	}
	//for(i=0;i<m;i++)printf("%lu",v[i].size());
}