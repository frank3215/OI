#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = sqrt(1e5), m = n+1, ans = 0;
	cin >> n >> m;
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			ans+=min(min(i,n-i-1),min(j-1,m-j-1));
	cout << ans << endl;
}
