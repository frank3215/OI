#include <bits/stdc++.h>
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a+i);
    }
    std::sort(a, a+n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i];
    }
    o = unique(b, b+n) - b;
    T[0] = init(0, o-1);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(a, a+n);
        T[1] = update(T[0], 0, o-1, a[i]);
    }
}
