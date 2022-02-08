#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 1e6 + 10;
int n;
double sum[maxn], prod[maxn], p[maxn], ans;
int main() {
    freopen("cowdate.in", "r", stdin);
    freopen("cowdate.out", "w", stdout);
    scanf("%d", &n);
    prod[0] = 1;
    for (int i = 1; i <= n; ++i) {
        scanf("%lf", p+i);
        p[i]/=1e6;
        prod[i] = prod[i-1]*(1-p[i]);
        sum[i] = sum[i-1] + p[i]/(1-p[i]);
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= i; ++j) {
            ans = max(ans, (sum[i]-sum[j-1])*(prod[i]/prod[j-1]));
        }
    printf("%d", (int)(ans*1e6));
}
