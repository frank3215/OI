#include <bits/stdc++.h>
const char *sub1 = "1_998244353", *sub2 = "1?", *sub4 = "1wa_998244353";
const char *sub5 = "2p", *sub6 = "2u";
int pow(int a, int x, const int &m) {
	long long ans = 1;
	for (int i = 1; i <= x; ++i) {
		ans = ans*a%m;
	}
	return ans;
//	return (x?pow(a*a%m, x/2, m)*(x&1?x:1):1)%m;
}
int powa(int a, int x, const int &m) {
	int ans = 1;
	for (int i = 1; i <= x; ++i) {
		ans = (int)((unsigned)ans*(unsigned)a%m);
	}
	return ans;
//	return (x?pow(a*a%m, x/2, m)*(x&1?x:1):1)%m;
}
void solve1(int m) {
	int n, l, ans;
	char s[100];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		l = strlen(s);
//		printf("%d %s\n", l, s);
		ans = 1;
		for (int j = 0; j < l; ++j) {
			ans = (long long)pow(ans, 10, m)*pow(19, s[j]-'0', m)%m;
		}
		printf("%d\n", ans);
	}
}
void solvewa1(int m) {
	int n, l, ans;
	char s[100];
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%s", s);
		l = strlen(s);
//		printf("%d %s\n", l, s);
		ans = 1;
		for (int j = 0; j < l; ++j) {
			ans = (long long)powa(ans, 10, m)*powa(19, s[j]-'0', m)%m;
		}
		printf("%d\n", ans);
	}
}
//Second
const int maxn = 1e6+10;
int p[maxn], nop[maxn];
void pre() {
	for (int i = 2; i < maxn; ++i) {
		if (!nop[i]) {
			p[++p[0]] = i;
//			printf("%d\n", i);
		}
		for (int j = 1; j <= p[0] && p[j] * i < maxn; ++j) {
			nop[p[j]*i] = 1;
			if (i%p[j] == 0) break;
		}
	}
}
void solve2p() {
	pre();
	int n;
	scanf("%d", &n);
	int l, r;
	while (n--) {
		scanf("%d%d", &l, &r);
		for (int i = l; i <= r; ++i) {
			putchar(nop[i]?'.':'p');
		}
		putchar('\n');
	}
}
void solve2u() {
}
int main() {
	freopen("software.in", "r", stdin);
	freopen("software.out", "w", stdout);
	char s[100];
	scanf("%s", s);
	if (!strcmp(s, sub1)) solve1(998244353);
	else if (!strcmp(s, sub2)) solve1(1145141);
	else if (!strcmp(s, sub4)) solve1(998244353);
	else if (!strcmp(s, sub5)) solve2p();
	else if (!strcmp(s, sub6)) solve2u();
}
