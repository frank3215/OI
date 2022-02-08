#include <cstdio>
#include <cstring>
#define cmp(i, j, w) (sec[i] == sec[j] && sec[i+w] == sec[j+w])
const int maxn = 1e6;
int n, sa[maxn], rak[maxn], sec[maxn], m = 200;
char s[maxn];
namespace laji{
    int t[maxn];
    void sort() {
        memset(t, 0, sizeof(t));
        for (int i = 1; i <= n; ++i) t[rak[i]]++;
        for (int i = 1; i <= m; ++i) t[i] += t[i-1];
        for (int i = n; i >= 1; --i) sa[t[rak[sec[i]]]--] = sec[i];
    }
}
void debug() {
    printf("*****************\n");
    printf("下标"); for (int i = 1; i <= n; i++) printf("%d ", i);     printf("\n");
    printf("sa  "); for (int i = 1; i <= n; i++) printf("%d ", sa[i]); printf("\n");
    printf("rak "); for (int i = 1; i <= n; i++) printf("%d ", rak[i]); printf("\n");
    printf("sec "); for (int i = 1; i <= n; i++) printf("%d ", sec[i]); printf("\n");
}
using laji::sort;
int main() {
    scanf("%s", s+1);
    n = strlen(s+1);
    for (int i = 1; i <= n; ++i) {
        rak[i] = s[i];
        sec[i] = i;
    }
    sort();
    for (int w = 1, p = 1; p < n; w<<=1, m=p) {
        for (p = 1; p <= w; ++p) sec[p] = n-w+p;
        for (int i = 1; i <= n; ++i) if (sa[i] > w) sec[p++] = sa[i]-w;
        sort();
        memcpy(sec, rak, sizeof(sec));
        rak[sa[1]] = p = 1;
        for (int i = 2; i <= n; ++i) {
            rak[sa[i]] = (cmp(sa[i], sa[i-1], w) ? p : ++p);
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d ", sa[i]);
    }
}
