#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+10, L = 22;

int n, f[L][N], a[N];
char s[N];

namespace SA {
    int sa[N], rk[N], rkk[N], tp[N], rk2[N], tx[N];

    inline void tsort(int *sa, int *rk, int *tp, int m) {
        for (int i = 0; i <= m; i++) tx[i] = 0;
        for (int i = 1; i <= n; i++) ++tx[rk[i]];
        for (int i = 1; i <= m; i++) tx[i] += tx[i-1];
        for (int i = n; i; i--) sa[tx[rk[tp[i]]]--] = tp[i];
    }

    inline bool pd(int i, int t) {
        return tp[sa[i-1]] == tp[sa[i]] && tp[f[t][sa[i-1]]] == tp[f[t][sa[i]]];
    }

    inline void main() {
        int p = 0;
        for (int i = 1; i <= n; i++) a[i] = s[i] - 'a' + 1, tp[i] = i;
        tsort(sa, a, tp, n);
        rk[sa[1]] = rkk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++) {
            rk[sa[i]] = a[sa[i-1]] == a[sa[i]] ? p : ++p;
            rkk[sa[i]] = i;
        }
        for (int w = 1, t = 0; w < n; w <<= 1, ++t) {
            for (int i = 1; i <= n; i++) rk2[i] = rkk[f[t][i]];
            tsort(tp, rk2, sa, n);
            tsort(sa, rk, tp, p);
            swap(rk, tp);
            rk[sa[1]] = rkk[sa[1]] = p = 1;
            for (int i = 2; i <= n; i++) {
                rk[sa[i]] = pd(i, t) ? p : ++p;
                rkk[sa[i]] = i;
            }
        }
    }
}

int main() {
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &f[0][i]);
		for (int j = 1; j < L; ++j)
			f[j][i] = f[j-1][f[j-1][i]];
	}
	scanf("%s", s+1);
	SA::main();
	for (int i = 1; i <= n; ++i) {
		printf("%d%c", SA::sa[i], " \n"[i==n]);
	}
}
