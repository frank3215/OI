#include <bits/stdc++.h>
using namespace std;

int gcd(int x,int y){ return y?gcd(y,x%y):x; }

int main() {
	int n;
	cin>>n;
	int ans = 0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			ans += gcd(i,j)==1;
	cout<<ans<<endl;
}
