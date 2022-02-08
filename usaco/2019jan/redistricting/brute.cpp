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
    for (int i = 1; i <= n; ++i) {
        f[i] = n;
        for (int j = 1; j <= std::min(i, k); ++j) {
            f[i] = std::min(f[i-j] + ((a[i] - a[i-j]) <= 0), f[i]);
        }
    }
    printf("%d", f[n]);
}
