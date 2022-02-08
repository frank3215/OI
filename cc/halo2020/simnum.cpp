#include<bits/stdc++.h>
using namespace std;

namespace {
	const int N = 1e5+10, LOGN = 20;
	int n, m;
	char s[N];
	int tmp[N], rank[N], sec[N], sa[N], height[N], h[N];
	int st[N][LOGN], log[N];

	int query(int x, int y) {
		if (x == y) return n-sa[x]+1;
		if (x > y) swap(x, y);
		++x;
		int l = log[y-x+1];
		return min(st[x][l], st[y-(1<<l)+1][l]);
	}

	void _print(int *a) {
		for (int i = 1; i <= n; ++i) {
			printf(" %d", a[i]);
		}
		putchar('\n');
	}
#define print(x) cout<<#x;_print(x)

	void sort() {
		for (int i = 0; i <= m; ++i) tmp[i] = 0;
		for (int i = 1; i <= n; ++i) tmp[rank[i]]++;
		for (int i = 1; i <= m; ++i) tmp[i] += tmp[i-1];
		for (int i = n; i; --i) sa[tmp[rank[sec[i]]]--] = sec[i];
	}

	void solve() {
		scanf("%s", s+1);
		// SA
		n = strlen(s+1);
		m = 256;
		for (int i = 1; i <= n; ++i) rank[i] = s[i], sec[i] = i;
		sort();
		memcpy(sec, rank, sizeof(sec));
		m = rank[sa[1]] = 1;
		for (int i = 2; i <= n; ++i) {
			if (sec[sa[i]] != sec[sa[i-1]]) m++;
			rank[sa[i]] = m;
		}
		for (int w = 1; m < n; w <<= 1) {
			for (int i = 1; i <= w; ++i) sec[i] = n-i+1;
			int p = w;
			for (int i = 1; i <= n; ++i)
				if (sa[i] > w) sec[++p] = sa[i]-w;
			sort();
			memcpy(sec, rank, sizeof(sec));
			m = rank[sa[1]] = 1;
			for (int i = 2; i <= n; ++i) {
				if (sec[sa[i]] != sec[sa[i-1]] || (sa[i]+w<=n?sec[sa[i]+w]:0) != (sa[i-1]+w<=n?sec[sa[i-1]+w]:0)) m++;
				rank[sa[i]] = m;
			}
		}
		for (int i = 1; i <= n; ++i) {
			h[i] = max(h[i-1]-1,0);
			while (s[i+h[i]] == s[sa[rank[i]-1]+h[i]]) ++h[i];
			height[rank[i]] = h[i];
		}

		// ST
		for (int i = 1; i <= n; ++i) {
			st[i][0] = height[i];
		}
		log[1] = 0;
		for (int i = 2; i <= n; ++i) {
			log[i] = log[i>>1]+1;
		}
		for (int i = 1; i < LOGN; ++i) {
			for (int j = 1; j <= n-(1<<i)+1; ++j) {
				st[j][i] = min(st[j][i-1], st[j+(1<<(i-1))][i-1]);
			}
		}

		// Calc
		//print(height);
		long long ans = 0;
		for (int i = 1; i <= n; ++i) {
			//printf("%d %d %d\n", i, rank[1], query(i, rank[1]));
			ans += query(i, rank[1]);
		}
		cout << ans << endl;
	}
}

int main(){
	int t;
	scanf("%d", &t);
	while (t--) {
		solve();
	}
}
