#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5+10;

int n, m;
int a[maxn];

signed main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a+i);
    }
    int ans = 0, nans = 0;
    for (int i = 62; ~i; --i) {
        int cnt = 0, cur = 0;
        nans |= 1ll << i;
        for (int j = 1; j <= n; ++j) {
            cur ^= a[j];
            if ((cur & nans) == 0) {
                cur = 0;
                cnt++;
            }
        }
        if (!(cur == 0 && cnt >= m)) {
            nans ^= 1ll << i;
            ans |= 1ll << i;
        }
        //for (int i = 63; ~i; --i) cout << ((ans>>i)&1); cout << endl;
        //for (int i = 63; ~i; --i) cout << ((nans>>i)&1); cout << endl;
        //cout << ans << ' ' << nans << endl;
    }
    printf("%lld\n", ans);
}
