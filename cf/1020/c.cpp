#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using std::sort;
const int maxn=3010;
int n,m,p,c,l[maxn],mx,sum=0,num=0;
long long mn=1e15;
std::vector<int> vp[maxn];
std::pair<int,int> v[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d%d",&p,&c),
		vp[p].push_back(c),
		v[i] = std::make_pair(c,p);
	for(int i=1;i<=m;i++)
		if((l[i]=vp[i].size()))
			sort(vp[i].begin(),vp[i].end());
	sort(v,v+n);

	for(int vote=std::max(l[1],1);vote<=n;vote++){
		long long cost=0,cur=l[1],tot[maxn]={};
		for(int i=2,j;i<=m;i++){
			for(j=0;j+vote<=l[i];j++,cur++)
				cost+=vp[i][j];
			tot[i]+=j;
		}
		if(cur>vote) continue;
		if(cur<vote)
			for(int i=0;cur<vote&&i<n;i++){
				if(v[i].second==1) continue;
				if(tot[v[i].second]){
					tot[v[i].second]--;
					continue;
				}
				cost+=v[i].first,cur++;
			}
		mn=std::min(mn,cost);
	}
	std::cout<<mn<<std::endl;
}
