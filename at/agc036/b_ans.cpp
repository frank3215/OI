#include <bits/stdc++.h>
using namespace std;

using ll=long long;
#define int ll

#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=a;i--)
#define per(i,b) gnr(i,0,b)
#define pb push_back
#define eb emplace_back
#define a first
#define b second
#define bg begin()
#define ed end()
#define all(x) x.bg,x.ed
#ifdef LOCAL
#define dmp(x) cerr<<__LINE__<<" "<<#x<<" "<<x<<endl
#else
#define dmp(x) void(0)
#endif

template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

template<class t> using vc=vector<t>;
template<class t> using vvc=vc<vc<t>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class t,class u>
ostream& operator<<(ostream& os,const pair<t,u>& p){
	return os<<"{"<<p.a<<","<<p.b<<"}";
}

template<class t> ostream& operator<<(ostream& os,const vc<t>& v){
	os<<"{";
	for(auto e:v)os<<e<<",";
	return os<<"}";
}

signed main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout<<fixed<<setprecision(20);
	
	int n,k;cin>>n>>k;
	k*=n;
	vi a(n);
	map<int,vi> idx;
	rep(i,n){
		cin>>a[i];
		idx[a[i]].pb(i);
	}
	vi w(n);
	for(auto kv:idx){
		int s=kv.b.size();
		kv.b.pb(kv.b[0]+n);
		rep(i,s){
			w[kv.b[i]]=kv.b[i+1]-kv.b[i]+1;
		}
	}
	const int inf=LLONG_MAX/3;
	const int L=60;
	vc<vi> nx{w};
	rep(_,L){
		vi&x=nx.back();
		vi y(n);
		rep(i,n)y[i]=min(inf,x[i]+x[(i+x[i])%n]);
		nx.pb(y);
	}
	int cur=0;
	per(i,L+1){
		if(cur+nx[i][cur%n]<=k)
			cur+=nx[i][cur%n];
	}
	if(cur==k)
		return 0;
	vi ans;
	set<int> has;
	rng(i,cur%n,n){
		if(has.count(a[i])){
			while(1){
				int v=ans.back();
				ans.pop_back();
				has.erase(v);
				if(v==a[i])break;
			}
		}else{
			ans.pb(a[i]);
			has.insert(a[i]);
		}
	}
	rep(i,ans.size()){
		cout<<ans[i];
		if(i<int(ans.size())-1)
			cout<<" ";
		else
			cout<<endl;
	}
}

