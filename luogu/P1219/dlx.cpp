#include <bits/stdc++.h>
using namespace std;

const int N = 13, mx = (N*N)*4+N*6+10;
vector<int> tmp;
vector<vector<int> > ans;
int n, cnt;

namespace DLX{
	int m;
	int u[mx], d[mx], l[mx], r[mx], row[mx], col[mx], h[mx], s[mx], t;
	int cur[mx];
	void init(int _m) {
		m = _m;
		for (int i = 0; i <= m; ++i)
			l[i]=i-1, r[i]=i+1, u[i]=d[i]=i, s[i]=0;
		l[0]=m, r[m]=0;
		s[0] = mx;
		memset(h, -1, sizeof(h));
		t = m;
	}
	void insert(int R, int C) {
		++t;
		col[t]=C, row[t]=R;
		u[t]=C, d[t]=d[C]; u[d[t]]=d[u[t]]=t, s[C]++;
		if (h[R]==-1) l[t]=r[t]=t, h[R]=t;
		else {l[t]=h[R], r[t]=r[h[R]]; l[r[t]]=r[l[t]]=t;}
	}
	void remove(int C) {
//		printf("REMOVE %d\n", C);
		l[r[C]]=l[C], r[l[C]]=r[C];
		for (int i=d[C]; i!=C; i=d[i])
			for (int j=r[i]; j!=i; j=r[j])
				d[u[j]]=d[j], u[d[j]]=u[j], s[col[j]]--;
//		printf("REMOVE DONE\n", C);
	}
	void recall(int C) {
//		printf("RECALL %d\n", C);
		l[r[C]]=r[l[C]]=C;
		for (int i=d[C]; i!=C; i=d[i])
			for (int j=r[i]; j!=i; j=r[j])
				d[u[j]]=u[d[j]]=j, s[col[j]]++;
//		printf("RECALL DONE\n", C);
	}
	void dance(int dep) {
//		printf("%d(%d)\n",dep,r[0]);
		if (dep == n) {
			cnt++;
			for (int i = 0; i < dep; ++i)
				tmp[(cur[i]-1)/n] = (cur[i]-1)%n+1;
			ans.push_back(tmp);
			if (ans.size() == 4) {
				sort(ans.begin(), ans.end());
				ans.pop_back();
			}
			return;
		}
		int C=0;
		for (int i=r[0]; i != 0 && i <= 2*n; i=r[i]) {
			assert(r[i] == 0 || r[i] > i);
			if (s[i] && s[i]<s[C]) C=i;
		}
		if (!C) return;
//		printf("%d\n", C);
		remove(C);
		for (int i=d[C]; i!=C; i=d[i]) {
			for (int j=r[i]; j!=i; j=r[j]) remove(col[j]);
			cur[dep] = row[i];
			dance(dep+1);
			for (int j=l[i]; j!=i; j=l[j]) recall(col[j]);
		}
		recall(C);
	}
}

void solve() {
	cin >> n;
	DLX::init(6*n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			DLX::insert(i*n+j+1, i+1); //[1, n]
			DLX::insert(i*n+j+1, n+j+1); //[n+1, 2*n]
			DLX::insert(i*n+j+1, 2*n+i+j+1); //[2*n+1, 4*n-1]
			DLX::insert(i*n+j+1, 5*n+i-j); //[4*n+1, 6*n-1]
		}
	tmp = vector<int>(n);
	DLX::dance(0);
	for (int i = 0; i < ans.size(); ++i) {
		for (int j = 0; j < n; ++j)
			cout << ans[i][j] << ' ';
		cout << endl;
	}
	cout << cnt << endl;
}

int main() {
	solve();
}
