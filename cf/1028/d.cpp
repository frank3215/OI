#include <cstdio>
#include <iostream>
#include <string>
#include <set>
using namespace std;
const long long maxn=364000,MOD=1e9+7,inf=308990000;
long long t,p,vis[maxn],ans=1,q,prices[maxn],mx=inf,mn=0,siz=0,last=0;
string s,cmd[maxn];
set<long long> st;
set<long long>::iterator si;
int main(){
	cin >> t;
/*	for(int i=0;i<t;i++)
		cin >> cmd[i] >> prices[i];
*/
	for(int i=0;i<t;i++){
//		s=cmd[i],p=prices[i];
		cin >> s >> p;
		st.insert(0);
		st.insert(inf);
//		if(!siz) mx=inf,mn=0;
		if(s[1]=='D')
			st.insert(p),siz++,last+=(mn<p&&p<mx);
		else{
			if(mn<=p&&p<=mx)
				st.erase(p),ans=ans*((mn<p&&p<mx)+1)%MOD;
			else ans=0;
//			siz--;
			last=0;
			si=st.lower_bound(p);
			mx=*si;
			mn=*--si;
		}
	}
	cout << ans*(last+1)%MOD << endl;
}
