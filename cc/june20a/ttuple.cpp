#include <bits/stdc++.h>
#define pb push_back
#define A first
#define B second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b-1); i >= a; --i)
#define REP(i,a,b) for (int i = a; i <= b; ++i)
#define PER(i,a,b) for (int i = b; i >= a; --i)
#define F0R(i,b) FOR(i,0,b)
#define R0F(i,b) ROF(i,0,b)
#define R1P(i,b) REP(i,1,b)
#define P1R(i,b) PER(i,1,b)
#define int long long
using namespace std;

void solve() {
	int a[3], b[3];
	FOR(i,0,3) cin >> a[i];
	FOR(i,0,3) cin >> b[i];

	// Answer = 0?
	{
		int same = 0;
		FOR(i,0,3) same += a[i]==b[i];
		if (same == 3) { puts("0"); return; }
	}

	// Answer = 1?
	{
		int add = 0, mul = 0;
		FOR(i,0,3) {
			if (a[i] == b[i]) continue;
			if (!add) add = b[i]-a[i];
			if (a[i]+add != b[i]) add = -1;
			if (!mul) mul = b[i]/a[i];
			if (a[i]*mul != b[i]) mul = -1;
		}
		if (add != -1 || mul != -1) { puts("1"); return; }
	}

	// Answer = 2?
	{ // Add?
		vector<int> v;
		FOR(i,0,3) if (b[i] != a[i]) v.push_back(b[i]-a[i]);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		if ((int)v.size() == 2) { puts("2"); return; }
		if ((int)v.size() == 3 && v[0]+v[1] == v[2]) { puts("2"); return; }
	}

	{ // Mul?
		vector<int> v;
		FOR(i,0,3) if (b[i] != a[i]) {
			if (b[i]%a[i]) goto F1;
			v.push_back(b[i]-a[i]);
		}
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		if ((int)v.size() == 2) { puts("2"); return; }
		if ((int)v.size() == 3 && v[0]*v[1] == v[2]) { puts("2"); return; }
F1:	; // Fail
	}

	{ // Add-Mul?
		FOR(i,1,8) {
			FOR(j,1,8) {
				int add = 0, mul = 0;
				vector<int> v;
				F0R(k,3) {
					switch(((i>>k)&1)+2*((j>>k)&1)) {
						case 0:
							if (b[k] != a[k]) goto F;
							break;
						case 1:
							if (!mul) mul = b[k]/a[k];
							if (a[k]*mul != b[k]) goto F;
							break;
						case 2:
							if (!add) add = b[k]-a[k];
							if (a[k]+add != b[k]) goto F;
							break;
						case 3:
							v.push_back(k);
					}
				}
				//printf("%d %d: %d %d\n", i, j, add, mul);
				{ // Mul-Add?
					vector<pair<int,int> > u;
					if ((int)v.size() >= 2) {
						for (auto x: v) for (auto y: v) if (x != y) {
							if ((a[x] == a[y])+(b[x]==b[y]) == 1) goto F2;
						}
						for (auto x: v) u.push_back(make_pair(a[x],b[x]));
						sort(u.begin(), u.end());
						u.erase(unique(u.begin(), u.end()), u.end());
						int padd = add, pmul = mul;
						if ((int)u.size() >= 2) {
							if ((u[1].B-u[0].B)%abs(u[1].A-u[0].A)) goto F2;
							mul = (u[1].B-u[0].B)/(u[1].A-u[0].A);
							add = u[1].B-u[1].A*mul;
							if (mul <= 0 || add <= 0) goto F2;
							if ((padd && padd != add) || (pmul && pmul != mul)) goto F2;
						}
					}
					for (auto x: v) {
						if (add && mul && a[x]*mul+add != b[x]) goto F2;
						if (!add && mul && a[x]*mul >= b[x]) goto F2;
						if (add && !mul && (b[x]-add)%a[x]) goto F2;
						if (!add && !mul && a[x] == b[x]) goto F2;
					}
					puts("2"); return;
F2:				;// Fail
				}
				{ // Add-Mul?
					for (auto x: v) {
						if (add && mul && (a[x]+add)*mul != b[x]) goto F3;
						if (!add && mul) {
							if (b[x]%mul) goto F3;
							add = b[x]/mul-a[x];
						}
						if (add && !mul) {
							if (a[x]+add == 0) {
								if (b[x] == 0) continue;
								else goto F3;
							}
							if (b[x]%(a[x]+add)) goto F3;
							mul = b[x]/(a[x]+add);
						}
						if (!add && !mul && a[x] == b[x]) goto F3;
					}
					if ((int)v.size() >= 2) {
						for (auto x: v) for (auto y: v) if (x != y) {
							if ((a[x] == a[y])+(b[x]==b[y]) == 1) goto F3;
						}
						vector<pair<int,int> > u;
						for (auto x: v) u.push_back(make_pair(a[x],b[x]));
						sort(u.begin(), u.end());
						u.erase(unique(u.begin(), u.end()), u.end());
						if ((int)u.size() >= 2) {
							if ((u[1].B-u[0].B)%abs(u[1].A-u[0].A)) goto F3;
							mul = (u[1].B-u[0].B)/(u[1].A-u[0].A);
							add = (u[1].B-u[1].A*mul)/mul;
							if ((padd && padd != add) || (pmul && pmul != mul)) goto F3;
						}
					}
					puts("2"); return;
F3:				;// Fail
				}
F:				;// Fail
			}
		}
	}
	// Answer = 3
	puts("3");
}

signed main() {
	int t;
	cin >> t;
	while (t--) solve();
}
