#include <cstdio>

const int maxn = 6e5+10;

char s[maxn];
int n, cur, mn, pos, ans, L, R;
int st[maxn], l[maxn], r[maxn], top, tot, fa[maxn], cnt[maxn];

int main() {
	scanf("%d%s", &n, s+1);
	for (int i = 1; i <= n; ++i) {
		cur += (s[i]=='('?1:-1);
		s[i+n] = s[i];
		if (cur < mn) mn = cur, pos = i;
	}
	if (cur != 0) return printf("0\n1 1\n"),0;
//	printf("%d\n", pos);
	for (int i = pos+1; i <= pos+n; ++i) {
		if (s[i] == '(')
			st[++top] = ++tot, l[tot] = i;
		else {
//			printf("%d %d  ", l[st[top]], i);
			r[st[top]] = i, fa[st[top]] = st[top-1], cnt[st[--top]]++;
//			printf("%d %d\n", st[top], cnt[st[top]]);
		}
	}
	ans = cnt[0], R=L=1;
	for (int i = 1; i <= tot; ++i) {
//		printf("%d %d %d %d\n", l[i], r[i], cnt[i], fa[i]);
		if (!fa[i]) {
			if (cnt[i]+1 > ans)
				ans = cnt[i]+1, L = l[i], R = r[i];
		}
		else if (!fa[fa[i]]) {
			if (cnt[i]+cnt[0]+1 > ans)
				ans = cnt[i]+cnt[0]+1, L = l[i], R = r[i];
		}
	}
	printf("%d\n%d %d\n", ans, (L-1)%n+1, (R-1)%n+1);
}
