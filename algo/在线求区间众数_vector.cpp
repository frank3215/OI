#include<iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
const int MAXN=100010;
vector<int> vec[MAXN];
map<int,int> mp;
int id,n,m,dp[1000][1000],cnt[MAXN],s[MAXN],val[MAXN],pos[MAXN];

void pre(int x){
	memset(cnt,0,sizeof(cnt));
	int mx=0;
	int ans=0;
	for(int i=(x-1)*m+1;i<=n;i++){
		cnt[s[i]]++;
		int tmp=pos[i];
		if(cnt[s[i]]>mx||(cnt[s[i]]==mx&&val[s[i]]<val[ans])){
			ans=s[i];
			mx=cnt[s[i]];
		}
		dp[x][tmp]=ans;
	}
}
int querr(int l,int r,int x){
	return upper_bound(vec[x].begin(),vec[x].end(),r)-lower_bound(vec[x].begin(),vec[x].end(),l);	
}
int query(int l,int r){
	int ans,mx;
	ans=dp[pos[l]+1][pos[r]-1];
	mx=querr(l,r,ans);
	for(int i=l;i<=min(r,pos[l]*m);i++){
		int t=querr(l,r,s[i]);
		if(t>mx||(t==mx&&val[s[i]]<val[ans])){
			ans=s[i];
			mx=t;
		}
	}
	if(pos[l]!=pos[r]){
		for(int i=(pos[r]-1)*m+1;i<=r;i++){
			int t=querr(l,r,s[i]);
			if(t>mx||(t==mx&&val[s[i]]<val[ans])){
				ans=s[i];
				mx=t;
			}
		}
	}
	return ans;
}
int main(){
	cin>>n;
	m=sqrt(n);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(!mp[s[i]])
			mp[s[i]]=++id,
			val[id]=s[i];
		s[i]=mp[s[i]];
		vec[s[i]].push_back(i);
	}
	for(int i=1;i<=n;i++) pos[i]=(i-1)/m+1;
	for(int i=1;i<=pos[n];i++) pre(i);
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		if(l>r) swap(l,r);
		cout<<val[query(l,r)]<<endl;
	}
}