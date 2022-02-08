#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;
typedef long long ll;
const ll NUL = 0xc0c0c0c0c0c0c0c0;

namespace sam{
const int N = ::N<<1, L = 21, S = 26;
int link[N][L], ch[N][S], len[N], cnt, last; int end[N];
vector<int> son[N];
void init() {
	memset(link+1, 0, cnt*sizeof(link[0]));
	memset(ch+1, 0, cnt*sizeof(ch[0]));
	memset(end+1, 0, cnt*sizeof(end[0]));
	memset(len+1, 0, cnt*sizeof(len[0]));
	for (int i = 1; i <= cnt; ++i) son[i].clear();
	cnt = last = 1; link[1][0] = 0; len[1] = 0;
}
void extend(int x) {
	int cur = ++cnt, p;
	len[cur] = len[last]+1;
	end[len[cur]] = cur;
	for (p = last; p && !ch[p][x]; p = link[p][0]) ch[p][x] = cur;
	if (!p) {
		link[cur][0] = 1;
	} else {
		if (len[p]+1 == len[ch[p][x]]) {
			link[cur][0] = ch[p][x];
		} else {
			int q = ch[p][x], nq = ++cnt;
			memcpy(ch[nq], ch[q], sizeof(ch[nq]));
			link[nq][0] = link[q][0];
			len[nq] = len[p]+1;
			for (; p && ch[p][x] == q; p = link[p][0]) ch[p][x] = nq;
			link[q][0] = nq;
			link[cur][0] = nq;
		}
	}
	last = cur;
}
void dfs(int u) {
	for (int i = 1; i < L; ++i) {
		link[u][i] = link[link[u][i-1]][i-1];
	}
	for (int i = 0; i < (int)son[u].size(); ++i) {
		int v = son[u][i];
		dfs(v);
	}
}
void pre() {
	for (int i = 2; i <= cnt; ++i) son[link[i][0]].push_back(i);
	dfs(1);
}
int find(int l, int L) {
	int ret = end[l];
	for (int k = sam::L-1; ~k; --k)
		if (len[link[ret][k]] >= L) ret = link[ret][k];
	return ret;
}
}

const int NN = N*7, M = N*9;
int len[N<<1], val[NN], b[N<<1];
bool cmp(int i, int j) {
	return len[i]==len[j] ? b[i]>b[j] : len[i]<len[j];
}

int n; int na, nb;
int head[NN], nxt[M], to[M], tot;
void clear(int n) {
	memset(head+1, 0, n*sizeof(head[0]));
	tot = 0;
}
void add(int u, int v) {
	nxt[++tot] = head[u], to[tot] = v, head[u] = tot;
}

ll vis[NN];
ll dfs(int u) {
	if (vis[u] != NUL) {
		return vis[u];
	}
	vis[u] = -1;
	ll ans = val[u];
	for (int i = head[u]; i; i = nxt[i]) {
		int v = to[i];
		ll ret = dfs(v);
		if (ret == -1) return -1;
		ans = max(ans, val[u]+ret);
	}
	return vis[u] = ans;
}

char s[N];
vector<int> v[sam::N];
int m;
void solve() {
	// string
	scanf("%s", s+1);
	n = strlen(s+1);
	sam::init();
	for (int i = n; i >= 1; --i) sam::extend(s[i]-'a');
	sam::pre();
	// clear
	memset(val+1, 0, (2*sam::N+2*na+nb)*sizeof(val[0]));
	memset(b+1, 0, (na+nb)*sizeof(b[0]));
	memset(len+1, 0, (na+nb)*sizeof(len[0]));
	for (int i = 0; i < sam::N; ++i) v[i].clear();
	// a
	scanf("%d", &na);
	for (int i = 1; i <= na; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		int u = sam::find(n-l+1, r-l+1); v[u].push_back(i);
		len[i] = r-l+1; b[i] = 0;
	}
	// b
	scanf("%d", &nb);
	for (int i = na+1; i <= na+nb; ++i) {
		int l, r; scanf("%d%d", &l, &r);
		int u = sam::find(n-l+1, r-l+1); v[u].push_back(i);
		len[i] = r-l+1; b[i] = 1;
	}
	// dominate
#define S(x) (x)
#define S1(x) (sam::cnt + (x))
#define A(x) (sam::cnt*2 + (x))
#define A1(x) (sam::cnt*2 + na + (x))
#define B(x) (sam::cnt*2 + na + (x))
	clear(sam::cnt*2+na*2+nb);
	for (int i = 2; i <= sam::cnt; ++i) {
		sort(v[i].begin(), v[i].end(), cmp);
		add(S(i), S1(i));
		add(sam::link[i][0]+sam::cnt, i);
		int curA = i, preB = 0;
		for (int j = 0; j < (int)v[i].size(); ++j) {
			int x = v[i][j];
			if (b[v[i][j]] == 0) {
				add(curA, A1(x));
				add(A1(x), A(x));
				curA = A1(x);
				val[A(x)] = len[x];
				if (preB) {
					add(preB, curA);
					add(preB, S1(i));
					preB = 0;
				}
			} else {
				if (preB) {
					add(preB, B(x));
				}
				preB = B(x);
			}
		}
		if (preB) add(preB, S1(i));
	}
	scanf("%d", &m);
	int x, y;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &x, &y);
		add(A(x), B(na+y));
	}
	// calculate
	memset(vis+1, 0xc0, (2*sam::cnt+2*na+nb)*sizeof(vis[0]));
	ll ans = 0;
	for (int i = A(1); i <= A(na); ++i) {
		ll ret = dfs(i);
		if (ret == -1) { puts("-1"); return; }
		ans = max(ans, ret);
	}
	printf("%lld\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) solve();
}
