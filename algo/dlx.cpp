#include <bits/stdc++.h>
using namespace std;

const int mx = 81*9*3+4*9*9+10;
int ans, val[mx];
bool v[mx];

namespace DLX{
	int m;
	int u[mx], d[mx], l[mx], r[mx], row[mx], col[mx], h[mx], s[mx], t;
	int cur;
	void init(int _m) {
		m = _m;
		for (int i = 0; i <= m; ++i)
			l[i]=i-1, r[i]=i+1, u[i]=d[i]=i, s[i]=0;
		l[0]=m, r[m]=0;
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
		l[r[C]]=l[C], r[l[C]]=r[C];
		for (int i=d[C]; i!=C; i=d[i])
			for (int j=r[i]; j!=i; j=r[j])
				d[u[j]]=d[j], u[d[j]]=u[j], s[col[j]]--;
	}
	void recall(int C) {
		l[r[C]]=r[l[C]]=C;
		for (int i=d[C]; i!=C; i=d[i])
			for (int j=r[i]; j!=i; j=r[j])
				d[u[j]]=u[d[j]]=j, s[col[j]]++;
	}
	void dance(int dep) {
		if (r[0]==0) {
			ans = max(ans, cur);
			return;
		}
		int C=r[0];
		for (int i=r[0]; i!=0; i=r[i]) if (s[i]<s[C]) C=i;
		remove(C);
		for (int i=d[C]; i!=C; i=d[i]) {
			for (int j=r[i]; j!=i; j=r[j]) remove(col[j]);
			cur+=val[row[i]];
			dance(dep+1);
			for (int j=l[i]; j!=i; j=l[j]) recall(col[j]);
			cur-=val[row[i]];
		}
		recall(C);
	}
}

#define cell(i,j) ((i/3)*3+(j/3))
void init() {
	DLX::init(4*9*9);
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int mult = 6+min(min(i, 8-i), min(j, 8-j));
			for (int k = 1; k <= 9; ++k)
				val[(i*9+j)*9 + k] = mult*k;
		}
	}
}
void extract(int i, int j, int k, int &a0, int &a1, int &a2, int &a3, int &a4) {
	a0 = (i*9+j)*9 + k;
	a1 = cell(i,j)*9 + k;
	a2 = 9*9 + i*9 + k;
	a3 = 2*9*9 + j*9 + k;
	a4 = 3*9*9 + (i*9)+j+1;
}
void insert(int i, int j, int k) {
	extract(i,j,k,a0,a1,a2,a3,a4);
	DLX::insert(a0, a1);
	DLX::insert(a0, a2);
	DLX::insert(a0, a3);
	DLX::insert(a0, a4);
}
void solve() {
	init();
	int k, a0, a1, a2, a3, a4;
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			cin >> k;
			if (k) insert(i, j, k);
			else for (k = 1; k <= 9; ++k)
				insert(i, j, k);
		}
	}
	ans = -1;
	DLX::dance(0);
	cout << ans << endl;
}

int main() {
	solve();
}
