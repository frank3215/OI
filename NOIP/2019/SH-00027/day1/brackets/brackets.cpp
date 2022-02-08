/*
 * ~9:54
 */
#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5+10;
typedef long long ll;

int n, fa[maxn], brk[maxn], same[maxn], pre[maxn], cnt[maxn]; ll ret[maxn], ans;
char s[maxn];
stack<int> st;
vector<int> val[maxn<<1], son[maxn];

int vof(char c) {
	return c==')'?-1:1;
}

int main() {
	freopen("brackets.in", "r", stdin);
	freopen("brackets.out", "w", stdout);
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", fa+i);
		son[fa[i]].push_back(i);
	}
	pre[0] = -1;
	for (int i = 1; i <= n; ++i) {
		brk[i] = brk[fa[i]]+vof(s[i-1]);
		pre[i] = fa[i];
		same[i] = i;
		while (~pre[i] && brk[pre[i]] >= brk[i]) {
			if (brk[pre[i]] == brk[i]) {
				same[i] = pre[i];
				cnt[i] = cnt[same[i]]+1;
			}
			pre[i] = pre[pre[i]];
		}
		ret[i] = ret[fa[i]] + cnt[i];
		ans ^= i*ret[i];
	}
	cout << ans << endl;
}
