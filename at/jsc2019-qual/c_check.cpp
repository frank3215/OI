#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10, MOD = 1e9+7;;

int n;
char s[maxn<<1];
stack<char> st;

int c() {
	cin >> n >> s;
	long long ans = (s[0] == 'B');
	for (int i = 0; i < 2*n; ++i) {
//		cout << i << ' ' << st.size() << endl;
		if (!st.empty() && st.top() == s[i]) {
			ans = (ans*st.size())%MOD;
			st.pop();
		}
		else st.push(s[i]);
	}
//	cout << ans << endl;
	ans *= st.empty();
	for (int i = 1; i <= n; ++i) {
		ans = (ans*i)%MOD;
	}
	return ans;
}

int v[20];

void flip(int l, int r) {
	for (int i = l; i <= r; ++i)
		s[i] = (s[i]=='B')?'W':'B';
}
bool ok() {
	for (int i = 0; i < 2*n; ++i)
		if (s[i] == 'B') return false;
	return true;
}

int count(int k) {
	if (k == n) return ok();
	int res = 0, tmp;
	for (int i = 0; i < 2*n; ++i)
		if (!v[i]) tmp = i;
	v[tmp] = 1;
	for (int j = 0; j < 2*n; ++j)
		if (!v[j]) {
			v[j] = 1;
			flip(j, tmp);
			res += count(k+1);
			flip(j, tmp);
			v[j] = 0;
		}
	v[tmp] = 0;
	return res;
}

int main() {
	n = 5;
	for (int i = 0; i < (1<<(2*n)); ++i) {
		for (int j = 0; j < (2*n); ++j)
			s[j] = "BW"[(i>>j)&1];
		int tmp = count(0);
		if (tmp) {
			cout << s << ' ' << tmp << endl;
		}
	}
}
