#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define MOD(x,m) ((x)%(m)+(m))%(m)

const int maxm = 1e5+10, maxn = 5e4+10;

int n, m, t, x[maxm], y[maxm];
bitset<maxn> b[maxn], B;
bool dir[maxm];
int pos[maxn], cnt[maxn];

void print() {
	F0R(i,m) putchar(dir[i]?'v':'^');
}

void print1(int z) {
	B.reset();
	B.set(z);
	R0F(i,m) {
		dir[i] = B[y[i]];
		B[x[i]]=B[y[i]]=B[x[i]]|B[y[i]];
	}
	print();
}
void solve1() {
	F0R(i,n) b[i].set(i);
	R0F(i,m) b[x[i]] = b[y[i]] = (b[x[i]]|b[y[i]]);
//	F0R(i,n) cout << b[i] << endl;
	b[n].set();
	F0R(i,n) b[n] &= b[i];
	F0R(i,n) if (b[n].test(i)) { print1(i); return; }
	cout << -1 << endl;
}

void solve2() {
	if (n == 2) {
		cout << -1 << endl;
		return;
	}
	F0R(i,n) cnt[pos[i]=i]++;
	R0F(i,m) {
		if (pos[x[i]] != pos[y[i]]) {
			if (cnt[pos[x[i]]] > 1) {
				cnt[pos[x[i]]]--, cnt[pos[y[i]]]++;
				dir[i] = 1;
				pos[x[i]] = pos[y[i]];
			} else {
				cnt[pos[y[i]]]--, cnt[pos[x[i]]]++;
				dir[i] = 0;
				pos[y[i]] = pos[x[i]];
			}
		}
	}
	print();
}

int main() {
	cin >> n >> m >> t;
	F0R(i,m) {
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
	}
	if (t == 1) solve1();
	else solve2();
}
