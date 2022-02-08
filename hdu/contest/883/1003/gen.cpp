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
	freopen("a.in", "w", stdout);
#endif
	int t = 3;
	printf("%d\n", t);
	while (t--) {
		int n = 200, k = 10;
		printf("%d %d\n", n, k);
		int N = 2*n;
		FOR(i,0,k) N <<= 1;
		print(i, N, i+1);
	}
}
