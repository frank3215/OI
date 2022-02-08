#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxt=350,maxn=1e5+maxt;
int n,m,t,nt,i,j,k,l,r,L,R,ll,rr,cur,ans,lb[maxn],mode[maxt][maxt],mx[maxt][maxt],a[maxn],b[maxn],sum[maxt][maxn],times[maxn],tmp[maxn],bl[maxn];
int main(){
	scanf("%d",&n);
	t=int(sqrt(n)+1);
	nt=(n-1)/t;
	//printf("%d %d\n",n,t);
	for(i=0;i<n;i++){
		scanf("%d",a+i);
		bl[i]=i/t;
		if(!i%t) lb[i]=i;
	}
	memcpy(b,a,n*sizeof(int));
	std::sort(b,b+n);
	m=std::unique(b,b+n)-b;
	for(i=0;i<n;i++)
		a[i]=std::lower_bound(b,b+m,a[i])-b;
	for(i=0;i<=nt;i++)
		for(j=i+1;j<=nt+1;j++)
			for(k=(j-1)*t;k<j*t;k++)
				if(++sum[i][a[k]]>mx[i][j] || (sum[i][a[k]]==mx[i][j] && a[k] < mode[i][j]) )
					mx[i][j]=sum[i][a[k]],mode[i][j]=a[k];
	for(i=0;i<1;i++){
		scanf("%d%d",&l,&r);
		l--,r--;
		if(bl[l]==bl[r]){
			ans=cur=0;
			for(j=l;j<=r;j++) times[a[j]]=0;
			for(j=l;j<=r;j++)
				if(++times[a[j]]>cur || (times[a[j]]==cur && a[j] < ans))
					cur=times[a[j]],ans=a[j];
		}
		else{
			L=bl[l]+1,R=bl[r],k=0,ll=L*t,rr=R*t;
			ans=mode[L][R],cur=mx[L][R];
			for(j=l;j<ll;j++) tmp[k++]=a[j];
			for(j=rr;j<=r;j++) tmp[k++]=a[j];
			for(j=0;j<k;j++) times[tmp[j]]=sum[L][tmp[j]]-sum[R][tmp[j]];
			for(j=0;j<k;j++)
				if(++times[tmp[j]]>cur || (times[tmp[j]]==cur && tmp[j] < ans))
					cur=times[tmp[j]],ans=tmp[j];
		}
		printf("%d %d\n",b[ans],cur);
	}
}
