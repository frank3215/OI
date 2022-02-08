#include <bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define ROF(i,a,b) for (int i = (b)-1; i >= a; --i)
using namespace std;

signed main() {
	FILE *f = fopen("seed", "r"); long long seed; fscanf(f, "%lld", &seed); srand(seed+time(NULL)); fclose(f);
	f = fopen("seed", "w"); fprintf(f, "%lld", (long long)rand()*RAND_MAX+rand()); fclose(f);

	int n = 50;
	printf("%d\n", n);
	FOR(i,0,n) {
		/*
		int a, b;
		a = rand()%100+1, b = rand()%100+1;
		if (a > b) swap(a, b);
		printf("%d %d\n", a, b);
		*/
		printf("1 100\n");
	}
}

