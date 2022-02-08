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

signed main() {
	FILE *f = fopen("seed", "r"); long long seed; fscanf(f, "%lld", &seed); srand(seed+time(NULL)); fclose(f);
	f = fopen("seed", "w"); fprintf(f, "%lld", (long long)rand()*RAND_MAX+rand()); fclose(f);
#ifndef ONLINE_JUDGE
	freopen("inverse.in", "w", stdout);
#endif
	int t = 5;
	printf("%d\n", t);
	while (t--) {
		int n = 8;
		printf("%d\n", n);
		vector<int> a(n);
		FOR(i,0,n) a[i] = i+1;
		random_shuffle(a.begin(), a.end());
		print(i,n,a[i]);
	}
}
