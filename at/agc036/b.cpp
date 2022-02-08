#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5+10;

int n;
long long k;
int a[maxn<<1], nxt[maxn], b[maxn<<1];
bool inq[maxn];
long long vis[maxn];
vector<pair<long long, int> > v;
vector<int> u;

int main() {
	cin >> n >> k;
	k *= n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a+i);
		a[i+n] = a[i];
	}

	memset(nxt, -1, sizeof(nxt));
	memset(b, -1, sizeof(b));
	for (int i = (n<<1)-1; ~i; --i) {
		b[i] = nxt[a[i]]+1;
		nxt[a[i]] = i;
	}
//	for (int i = 0; i < n; ++i) printf("a[%d]=%d, b[i]=%d\n", i, a[i], b[i]);

	memset(vis, -1, sizeof(vis));
	int i = 0;
	long long loop = 0;
	while (1) {
		if (~vis[i]) break;
		vis[i] = loop;
		v.push_back(make_pair(vis[i], i));
//		printf("%d(%d): %lld\n", i, a[i], loop);

		loop += b[i]-i;
		i = b[i]%n;
	}
	loop -= vis[i];
//	printf("i=%d, loop=%d\n", i, loop);
	if (k >= vis[i]) k = (k-vis[i])%loop+vis[i];
	int pos = (--upper_bound(v.begin(), v.end(), make_pair(k, 0)))->second;
//	printf("pos=%d\n", pos);
	for (long long j = vis[pos]+1, l = pos; j <= k; ++j) {
		if (inq[a[l]]) {
			while (inq[a[l]]) {
				inq[u.back()] = false;
				u.pop_back();
			}
		}
		else {
			u.push_back(a[l]);
			inq[a[l]] = true;
		}
		l = (l+1)%n;
//		for (int _ = 0; _ < u.size(); ++_) printf("%d ", u[_]); puts("");
	}
	for (int j = 0; j < u.size(); ++j) printf("%d ", u[j]); puts("");
}
