#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;
const long long maxn=364000,MOD=1e9+7,inf=308990000;
long long t,p,vis[maxn],ans,q,prices[maxn],mx=inf,mn=0,siz=0,last=0;
string s,cmd[maxn];
set<long long> st;
long long pow(long long a,int x){
	return x?pow(a*a%MOD,x/2)*(x&1?a:1)%MOD:1;
}
int main(){
	cin >> t;
/*	for(int i=0;i<t;i++)
		cin >> cmd[i] >> prices[i];*/

	for(int i=0;i<t;i++){
//		s=cmd[i],p=prices[i];
		cin >> s >> p;
		st.insert(0);
		st.insert(inf);
		if(!siz) mx=inf,mn=0;
		if(s[1]=='D')
			st.insert(p),siz++,last+=(mn<p&&p<mx);
		if(s[1]=='C'){
			if(mn<=p&&p<=mx)
				st.erase(p),ans+=(mn<p&&p<mx);
			else ans-=maxn;
			siz--,last=0;
			mn=*--st.lower_bound(p);
			mx=*st.upper_bound(p);
		}
	}
	cout << (ans<0?0:pow(2,ans+last));
}
