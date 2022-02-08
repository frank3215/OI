//It is made by M_sea
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <tr1/unordered_map>
#define re register
using namespace std;
using namespace std::tr1;

inline int read() {
    int X=0,w=1; char c=getchar();
    while (c<'0'||c>'9') { if (c=='-') w=-1; c=getchar(); }
    while (c>='0'&&c<='9') X=X*10+c-'0',c=getchar();
    return X*w;
}

typedef long long LL;
typedef unsigned long long ULL;
const int MAXN=5000000;

int v[MAXN+10];
int p[MAXN+10];
LL mu[MAXN+10],phi[MAXN+10];

inline void init() {
    v[1]=mu[1]=phi[1]=1;
    re int cnt=0;
    for (re int i=2;i<=MAXN;++i) {
        if (!v[i]) p[++cnt]=i,mu[i]=-1,phi[i]=i-1;
        for (re int j=1;j<=cnt&&i*p[j]<=MAXN;++j) {
            v[i*p[j]]=1;
            if (i%p[j]) mu[i*p[j]]=-mu[i],phi[i*p[j]]=phi[i]*phi[p[j]];
            else { mu[i*p[j]]=0,phi[i*p[j]]=phi[i]*p[j]; break; }
        }
    }
    for (re int i=1;i<=MAXN;++i) mu[i]+=mu[i-1],phi[i]+=phi[i-1];
}

unordered_map<int,LL> ansmu,ansphi;

inline LL S_phi(int n) {
    if (n<=MAXN) return phi[n];
    if (ansphi[n]) return ansphi[n];
    LL ans=0;
    for (re int l=2,r;r<2147483647&&l<=n;l=r+1) //特判
        r=n/(n/l),ans+=(r-l+1)*S_phi(n/l);
    return ansphi[n]=(ULL)n*(n+1ll)/2ll-ans; //转ULL避免溢出
}
inline LL S_mu(int n) {
    if (n<=MAXN) return mu[n];
    if (ansmu[n]) return ansmu[n];
    LL ans=0;
    for (re int l=2,r;r<2147483647&&l<=n;l=r+1) //同上
        r=n/(n/l),ans+=(r-l+1)*S_mu(n/l);
    return ansmu[n]=1ll-ans;
}

int main() {
    init();
    int T=read();
    while (T--) {
        int n=read();
        printf("%lld %lld\n",S_phi(n),S_mu(n));
    }
    return 0;
}
