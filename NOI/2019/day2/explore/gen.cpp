#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
using namespace std;

const int MAXN = 2e5+10;

int p[MAXN];
map<int,int> m[MAXN];

signed main() {
	FILE *f = fopen("seed", "r"); long long seed; fscanf(f, "%lld", &seed); srand(seed+time(NULL)); fclose(f);
	f = fopen("seed", "w"); fprintf(f, "%lld", (long long)rand()*RAND_MAX+rand()); fclose(f);
#ifndef ONLINE_JUDGE
	freopen("explore.in", "w", stdout);
#endif
	/*
	int N = 59998;
	printf("%d %d %d\n", 17*N, 17*N, 0);
	printf("%d %d\n", N, N/2);
	FOR(i,0,N) p[i] = i;
	random_shuffle(p, p+N);
	for (int i = 0; i < N; i += 2) printf("%d %d\n", p[i], p[i+1]);
	*/
	/*
	int N = 199997;
	printf("%d %d %d\n", 19*N, 18*N, 0);
	printf("%d %d\n", N, N-1);
	FOR(i,1,N) printf("%d %d\n", rand()%i, i);
	*/
	int N = 2e5, M = 3e5;
	int Q = 1e7;
	printf("%d %d %d\n", Q, Q, 2*M);
	printf("%d %d\n", N, M);
	FOR(i,0,M) {
		int u, v;
		do {
			u = rand()%N, v = rand()%N;
		} while (u == v || m[u][v]);
		m[u][v] = m[v][u] = 1;
		printf("%d %d\n", u, v);
	}
}
