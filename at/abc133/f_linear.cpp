#include <bits/stdc++.h>
#define debug //printf
using namespace std;

const int maxn = 1e5+10;

int n;

typedef long long ll;
const int LEN = 100000;
struct fastio{
  char s[LEN + 5]; int len,it;
  fastio(){
    it = len = 0;
  }
  char get(){
    if(it < len) return s[it++];
    it = 0, len = fread(s,1,LEN,stdin);
    return len ? s[it++] : EOF;
  }
  bool notend(){
    char c;
    for(c = get();c == ' ' || c == '\n';c = get());
    if(it) it--;
    return c != EOF;
  }
  void put(char c){
    if(len == LEN) fwrite(s,1,LEN,stdout), len = 0;
    s[len++] = c;
  }
  void flush(){
    fwrite(s,1,len,stdout);
    len = 0;
  }
}buff,bufo;
inline int getint(){
  char c; int res = 0, sig = 1;
  for(c = buff.get();c < '0' || c > '9';c = buff.get()) if(c == '-') sig = -1;
  for(;c >= '0' && c <= '9';c = buff.get())
    res = (res << 3) + (res << 1) + (c - '0');
  return sig * res;
}
inline void putll(ll x){
  if(!x) bufo.put('0');
  else if(x < 0) bufo.put('-'), x = -x;
  char s[25]; int k = 0;
  while(x){
    s[++k] = x % 10 + '0';
    x /= 10;
  }
  for(int i = k;i >= 1;i--) bufo.put(s[i]);
}

struct edge{ int a, b, c; };
struct query{ int i, v, x, y; };
vector<edge> g[maxn];
vector<query> q[maxn];
void add2(int a, int b, int c, int d) {
	g[a].push_back((edge){b, c, d});
	g[b].push_back((edge){a, c, d});
}

int f[maxn], v[maxn];
int find(int x) { return f[x]>0?f[x]=find(f[x]):x; }
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return;
	v[fy] = v[fx];
	if (f[fx] > f[fy]) swap(fx, fy);
	f[fx] -= f[fx]==f[fy];
	f[fy] = fx;
}

int dis[maxn], col[maxn], cdis[maxn];
int ans[maxn], lca[maxn];
void dfs(int u, int fa) {
	for (int i = 0; i < g[u].size(); ++i) {
		int v = g[u][i].a;
		if (v == fa) continue;
		dis[v] = dis[u] + g[u][i].c;
		col[g[u][i].b]++;
		cdis[g[u][i].b] += g[u][i].c;
		dfs(v, u);
		merge(u, v);
		col[g[u][i].b]--;
		cdis[g[u][i].b] -= g[u][i].c;
	}
	for (int i = 0; i < q[u].size(); ++i) {
		query &qq = q[u][i];
		debug(" %d %d %d %d: %d\n", qq.i, qq.v, qq.x, qq.y, ans[qq.i]);
		debug("%d: %d %d %d %d\n", qq.i, u, dis[u], cdis[qq.x], col[qq.x]*qq.y);
		if (qq.v) {
			ans[qq.i] += dis[u]-cdis[qq.x]+col[qq.x]*qq.y;
			if (!lca[qq.i] && dis[qq.v]) {
				lca[qq.i] = v[find(qq.v)];
				debug("lca: %d %d: %d\n", u, qq.v, lca);
				q[lca[qq.i]].push_back((query){qq.i, 0, qq.x, qq.y});
			}
		}
		else {
			ans[qq.i] -= 2*(dis[u]-cdis[qq.x]+col[qq.x]*qq.y);
		}
	}
}

int main() {
	int qq;
	n = getint(), qq = getint();
	int a, b, c, d;
	for (int i = 0; i < n-1; ++i) {
		a = getint(), b = getint(), c = getint(), d = getint();
		add2(a, b, c, d);
	}
	for (int i = 0; i < qq; ++i) {
		a = getint(), b = getint(), c = getint(), d = getint();
		q[c].push_back((query){i, d, a, b});
		q[d].push_back((query){i, c, a, b});
	}
	memset(f, -1, sizeof(f));
	for (int i = 1; i <= n; ++i) v[i] = i;
	dis[1] = 1;
	dfs(1, 0);
	for (int i = 0; i < qq; ++i) {
		putll(ans[i]);
		bufo.put('\n');
	}
	bufo.flush();
}
