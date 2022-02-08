#include <bits/stdc++.h>
using namespace std;

const int maxn = 3005;

int n;
char s[maxn<<1];

int main() {
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < 2*n; ++i) {
		int c = s[i]-'a';
		pos[c] = cnt[s[i]]++;
		if (cnt[0] == cnt[1]) pos[++pos[0]] = i;
	}
}
