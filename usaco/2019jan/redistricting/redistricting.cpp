#include <cstdio>
#include <algorithm>
const int maxn = 3e5 + 10;
int n, k, a[maxn], f[maxn];
char s[maxn];

int main() {
    freopen("redistricting.in", "r", stdin);
    freopen("redistricting.out", "w", stdout);
    scanf("%d%d", &n, &k);
    scanf("%s", s+1);
    for (int i = 1; i <= n; ++i) {
        a[i] = a[i-1] + (s[i]=='H'?1:-1);
    }

}
