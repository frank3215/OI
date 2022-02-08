#include <cstdio>
#include <algorithm>
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &u, &v);
        con(u, v), con(v, u);
    }
    
