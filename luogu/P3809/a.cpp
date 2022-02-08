#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6+10;

int n;
char s[maxn];
int m = 200, sa[maxn], rak[maxn], sec[maxn];

int t[maxn];
void sort() {
	memset(t, 0, m*sizeof(int));
	for (int i = 0; i < n; ++i) t[rak[i]]++;
	for (int i = 1; i < m; ++i) t[i] += t[i-1];
	for (int i = n-1; i >= 0; --i) sa[--t[rak[sec[i]]]] = sec[i];
}

void debug() {
    printf("*****************\n");
    printf("下标"); for (int i = 0; i < n; i++) printf("%d\t", i);     printf("\n");
    printf("sa  "); for (int i = 0; i < n; i++) printf("%d\t", sa[i]); printf("\n");
    printf("rak "); for (int i = 0; i < n; i++) printf("%d\t", rak[i]); printf("\n");
    printf("sec "); for (int i = 0; i < n; i++) printf("%d\t", sec[i]); printf("\n");
}

int main() {
	scanf("%s", s);
	n = strlen(s);
	for (int i = 0; i < n; ++i) {
		rak[i] = s[i];
		sec[i] = i;
	}
	sort();
//	debug();
	for (int w = 1, p = 0; p != n-1; w <<= 1, m = p+1) {
		for (p = 0; p < w; ++p) sec[p] = n-w+p;
		for (int i = 0; i < n; ++i) if (sa[i] >= w) sec[p++] = sa[i]-w;
		sort();
//		debug();
		memcpy(sec, rak, sizeof(sec));
		rak[sa[0]] = p = 0;
		for (int i = 1; i < n; ++i)
			rak[sa[i]] = (sec[sa[i]]==sec[sa[i-1]]&&sec[sa[i]+w]==sec[sa[i-1]+w]?p:++p);
//		debug();
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", sa[i]+1);
}
