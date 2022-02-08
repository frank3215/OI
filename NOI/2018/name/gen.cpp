#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
#define print(i,n,f) FOR(i,0,n) printf("%d%c", f, " \n"[i==n-1]);
using namespace std;

string gen(int n, int sig) {
	string ret;
	FOR(i,0,n) ret += 'a'+rand()%sig;
	return ret;
}

signed main() {
	FILE *f = fopen("seed", "r"); long long seed; fscanf(f, "%lld", &seed); srand(seed+time(NULL)); fclose(f);
	f = fopen("seed", "w"); fprintf(f, "%lld", (long long)rand()*RAND_MAX+rand()); fclose(f);
#ifndef ONLINE_JUDGE
	freopen("name.in", "w", stdout);
#endif
	int L = 5e0;
	cout << gen(L, 3) << endl;
	int n = 1e0, l = 2;
	cout << n << endl;
	while (n--) {
		int l = rand()%L+1, r = rand()%L+1;
		if (l > r) swap(l, r);
		cout << gen(l, 3) << ' ' << l << ' ' << r << endl;
	}
	return 0;
}
