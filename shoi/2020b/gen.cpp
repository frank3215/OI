#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,b,a) for (int i = (b-1); i >= a; --i)
using namespace std;

signed main() {
	FILE *f = fopen("seed", "r"); long long seed; fscanf(f, "%lld", &seed); srand(seed+time(NULL)); fclose(f);
	f = fopen("seed", "w"); fprintf(f, "%lld", (long long)rand()*RAND_MAX+rand()); fclose(f);

	int n = 50, m = 8, s = 1;
	set<pair<int,int> > st;
	printf("%d %d %d\n", n, m, s);
	FOR(i,0,m) {
		int u, v;
		do {
			u = rand()%n+1;
			v = rand()%n+1;
			if (u > v) swap(u, v);
		} while (u == v && !st.count(mp(u,v)));
		st.insert(mp(u,v));
		printf("%d %d\n", u, v);
	}
}

