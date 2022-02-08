#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10, MOD = 1e9+7;;

int n;
long long ans = 1;
char s[maxn<<1];
stack<char> st;

int main() {
	cin >> n >> s;
	for (int i = 0; i < 2*n; ++i) {
//		cout << i << ' ' << st.size() << endl;
		if (!st.empty() && st.top() == s[i]) {
			ans = (ans*st.size())%MOD;
			st.pop();
		}
		else {
			if (s[i] == 'W' && st.empty()) ans = 0;
			st.push(s[i]);
		}
	}
//	cout << ans << endl;
	ans *= st.empty();
	for (int i = 1; i <= n; ++i) {
		ans = (ans*i)%MOD;
	}
	cout << ans << endl;
}
