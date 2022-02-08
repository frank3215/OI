#include <cstdio>
#include <set>
#include <vector>
typedef std::pair<int, int> pll;
std::set<pll> m;
int p1 = 1e9+9, p2 = 1e9+7;
int b1 = 0xae67, b2 = 0xb48c;
const int maxn = 1e5+10;
int mul(int a, int b, int p) {return (long long)a*b%p;}
int pow(long long a, int k, int p) {return (k?pow(a*a%p,k/2,p)*(k&1?p:1):1)%p;}
int div(int a, int b, int p) {return mul(a, pow(b, p-2, p), p);}
struct tree{
    int head[maxn], nxt[maxn<<1], to[maxn<<1], tot;
    int siz[maxn], N;
    std::vector<int> leaves;
    pll hash[maxn<<1];
    tree(){tot = 1;}
    void con(int u, int v) {
        ++tot;
        to[tot] = v;
        nxt[tot] = head[u];
        head[u] = tot;
    }
    pll hash1(int u, int f = 0) {
        printf("%d\n", u);
        pll p = std::make_pair(1, 1);
        siz[u] = 1;
        for (int e = head[u]; e; e = nxt[e]) if ((e^f) != 1){
            int v = to[e];
            hash[e] = hash1(v, e);
            //siz[u] += siz[v];
            p.first = mul(p.first, b1 + hash[e].first, p1);
            p.second = mul(p.second, b2 + hash[e].second, p2);
        }
        if (f == 0) hash[0] = p;
        printf("(%d, %d, %d)\n", u, p.first, p.second);
        return p;
    }
    void hash2(int u, int f = 0) {
        pll p;
        if (f) std::make_pair(mul(b1 + hash[f^1].first, hash[f].first, p1), mul(b2 + hash[f^1].second, hash[f].second, p2));
        else p = hash[0];
        for (int e = head[u]; e; e = nxt[e]) if ((e^f) != 1) {
            hash[e^1] = std::make_pair(div(p.first, hash[e].first + b1, p1), div(p.second, hash[e].second + b2, p2));
        }
        if (siz[u] == 1) leaves.push_back(f);
    }
    int gethash(bool b) {
        hash1(1), hash2(1);
        if (b) {
            for (int i = 2; i <= tot; ++i) {
                m.insert(hash[i]);
                printf("(%d, %d, %d) ", i, hash[i].first, hash[i].second);
            }
        }
        else {
            sort(leaves.begin(), leaves.end());
            for (int i = 0; i < leaves.size(); ++i)
                if (m.count(hash[leaves[i]^1]))
                    return to[leaves[i]];
        }
        return 0;
    }
}A, B;
int main() {
    int n;
    scanf("%d", &n);
    A.N = n;
    B.N = n+1;

    int u, v;
    for (int i = 1; i < n; ++i) {
        scanf("%d%d", &u, &v);
        A.con(u, v), A.con(v, u);
    }
    A.gethash(1);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &u, &v);
        B.con(u, v), B.con(v, u);
    }
    printf("%d\n", B.gethash(0));
}
