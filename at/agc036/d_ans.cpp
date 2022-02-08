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
	
	int n;cin>>n;
	vvc<int> a(n+2,vi(n+2));
	rep(i,n)rep(j,n-1)
		cin>>a[i+1][j+(j>=i)+1];
	
	n++;
	const int inf=LLONG_MAX/3;
	vvc<int> dp(n,vi(n,inf));
	dp[0][0]=0;
	
	rng(i,1,n){
		vi x(i),y(i);
		rep(j,i){
			rng(k,i+1,n+1)
				x[j]+=a[k][j];
			if(j)x[j]+=x[j-1];
		}
		per(j,i){
			rng(k,j+1,i+1)
				y[j]+=a[j+1][k];
			if(j+1<i-1)
				y[j]+=y[j+1];
		}
		rep(j,i)
			rep(k,j+1)
				chmin(dp[i][j],dp[j][k]+x[j]-x[k]+y[j]);
	}
	
	cout<<*min_element(all(dp[n-1]))<<endl;
}

