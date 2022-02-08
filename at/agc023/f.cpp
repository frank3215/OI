#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

struct dat{
	int u, o, z;
	bool operator <(const dat &d) const { return 1ll*o*d.z > 1ll*z*d.o; }
}t[maxn];

int f[maxn];
int find(int x) { return f[x]?f[x]=find(f[x]):x; }

int n;
int p[maxn], v[maxn];
priority_queue<dat> pq;

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", p+i);
//		if (p[i] != i-1) printf("%d %d\n", i, p[i]);
	}
	for (int i = 1; i <= n; ++i) {
		scanf("%d", v+i);
//		if (v[i] != v[i-1]) printf("%d:%d-%d:%d\n", i-1, v[i-1], i, v[i]);
		if (v[i] == 1) t[i] = (dat){i,1,0};
		else t[i] = (dat){i,0,1};
		pq.push(t[i]);
	}
	long long ans = 0;
	while (!pq.empty()) {
		dat tmp = pq.top(); pq.pop();
		int x = tmp.u;
		if (x == 1 || tmp.o != t[x].o || tmp.z != t[x].z) continue;
		int y = find(p[x]); f[x] = y;
		ans += 1ll*t[y].o*t[x].z;
		t[y].o += t[x].o;
		t[y].z += t[x].z;
		pq.push(t[y]);
	}
	cout << ans << endl;
}
