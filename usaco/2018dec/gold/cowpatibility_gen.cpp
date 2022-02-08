#include <cstdlib>
#include <cstdio>
int n = 4, seed;
long long Random() {
	return rand() * (RAND_MAX + 1ll) + rand();
}
int Random(int m){
	return Random()%m;
}
int main() {
	FILE *sin=fopen("seed","r");
	fscanf(sin,"%d",&seed);
	srand(seed);
	seed = Random();
	FILE *sout=fopen("seed","w");
	fprintf(sout,"%d",seed);

	freopen("cowpatibility.in","w",stdout);
	printf("%d",n);
	for (int i=0; i<n; ++i) {
		for (int j=0; j<5; ++j) {
			printf("%c%d"," \n"[!j],Random(10)+1);
		}
	}
}
