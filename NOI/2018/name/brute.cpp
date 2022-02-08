#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 500505
#define M 1800505
#define reg register
#define lg2(x)(31-__builtin_clz(x))
typedef long long LL;
int n,sa[M],height[M],x[M],s[M],mgk,bel[M],m,QL[N],QR[N],y[M],st[22][M],nxt[M],head[N],node=0,rt[M],pp[M],len[N];
int ls[M*20],rs[M*20],sz[M*20];
char ss[N];
bool isk;
int _L,_R;
void add(int&o,int pr,int l,int r,int pos){
	sz[o=++node]=sz[pr]+1;
	if(l<r){
		const int mid=l+r>>1;
		if(pos<=mid)add(ls[o],ls[pr],l,mid,pos),rs[o]=rs[pr];else add(rs[o],rs[pr],mid+1,r,pos),ls[o]=ls[pr];
	}
}
void sort(){
	int m=mgk,c[M];
	for(int i=1;i<=m;++i)c[i]=0;
	for(int i=1;i<=n;++i)++c[x[i]=s[i]];
	for(int i=1;i<=m;++i)c[i]+=c[i-1];
	for(int i=n;i;--i)sa[c[x[i]]--]=i;
	for(int k=1,p;k<=n;k<<=1){
		p=0;
		for(int i=n-k+1;i<=n;++i)y[++p]=i;
		for(reg int i=1;i<=n;++i)if(sa[i]>k)y[++p]=sa[i]-k;
		for(reg int i=1;i<=m;++i)c[i]=0;
		for(reg int i=1;i<=n;++i)++c[x[i]];
		for(reg int i=1;i<=m;++i)c[i]+=c[i-1];
		for(reg int i=n;i;--i)sa[c[x[y[i]]]--]=y[i];
		std::swap(x,y);
		x[sa[1]]=p=1;
		for(int i=2;i<=n;++i)
		x[sa[i]]=y[sa[i]]==y[sa[i-1]]&&y[sa[i]+k]==y[sa[i-1]+k]?p:++p;
		if(p==n)break;
		m=p;
	}
	for(int i=1,k=0;i<=n;++i)
	if(x[i]>1){
		k-=!!k;
		const int j=sa[x[i]-1];
		while(s[i+k]==s[j+k])++k;
		height[x[i]]=k;
	}
}
inline int find(int l,int r){
    if(l>r)return n;
    const int lg=lg2(r-l+1);
    return std::min(st[lg][l],st[lg][r-(1<<lg)+1]);
}
void init(){
	for(reg int i=1;i<=n;++i)st[0][i]=height[i];
    for(int i=0;i<21;++i)
    for(reg int j=1;j<=n;++j)
    if(j+(1<<i)<=n)st[i+1][j]=std::min(st[i][j],st[i][j+(1<<i)]);else break;
    int pre[N];
    memset(pre,0,sizeof pre);
    for(int i=1;i<=n;++i)
    if(s[sa[i]]<='z'){
    	if(pre[bel[sa[i]]])
    	nxt[pre[bel[sa[i]]]]=i,pp[i]=pre[bel[sa[i]]];else head[bel[sa[i]]]=i;
    	pre[bel[sa[i]]]=i;
    }
}
void query(const int&ri,const int&le,int l,int r){
	if(sz[ri]==sz[le]||isk)return;
	if(_L<=l&&r<=_R)return(void)(isk=1);
	const int mid=l+r>>1;
	if(_L<=mid)query(ls[ri],ls[le],l,mid);
	if(mid<_R&&!isk)query(rs[ri],rs[le],mid+1,r);
}
bool check(int pos,int len,int l,int r){
	int L,ll,rr;
	ll=1,rr=pos-1;
	while(ll<=rr){
		const int mid=ll+rr>>1;
		if(find(mid+1,pos)>=len)rr=mid-1;else ll=mid+1;
	}
	L=rr;
	ll=pos+1,rr=n;
	while(ll<=rr){
		const int mid=ll+rr>>1;
		if(find(pos+1,mid)>=len)ll=mid+1;else rr=mid-1;
	}
	isk=0;
	_L=l,_R=r;
	query(rt[ll-1],rt[L],1,n);
	return isk;
}
int main(){
	memset(bel,-1,sizeof bel);
	mgk='z'+1;
	scanf("%s",ss);
	for(int i=0;ss[i];++i)
	s[++n]=ss[i],bel[n]=0;
	s[++n]=mgk++;
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%s%d%d",ss,QL+i,QR+i);
		for(int j=0;ss[j];++j)
		s[++n]=ss[j],bel[n]=i;
		len[i]=n;
		s[++n]=mgk++;
	}
	sort();
	init();
	for(reg int i=1;i<=n;++i)
	if(!bel[sa[i]])add(rt[i],rt[i-1],1,n,sa[i]);else rt[i]=rt[i-1];
	for(int i=1;i<=m;++i){
		LL ans=len[i]-sa[head[i]]+1;
		int mnid=sa[head[i]];
		for(int j=nxt[head[i]];j;j=nxt[j]){
			ans+=len[i]-sa[j]+1;
			ans-=find(pp[j]+1,j);
			mnid=std::min(mnid,sa[j]);
		}
		for(int j=mnid,L=mnid;s[j]<='z';++j){
			if(L<j)L=j;
			while(s[L]<='z'&&check(x[j],L-j+1,QL[i],QR[i]-L+j))++L;
			if(x[j]!=head[i])ans-=std::max(L-j-find(pp[x[j]]+1,x[j]),0);else
			ans-=L-j;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
