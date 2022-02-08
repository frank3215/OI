#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn=1<<10;
int n,m,mx,i,j,k,l,J,K,L,ans=0,ok[105][60]={},tot[105]={1,1},
dp[105][60][60]={0},map[105]={0},sum[maxn]={0};
bool nok[maxn]={0};
char c;
int main(){
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            scanf(" %c",&c);
            map[i+2]|=(c=='P')<<j;
        }
    for(i=0;i<maxn;i++)
        for(j=i;j;j>>=1) sum[i]+=j&1;
    for(j=0;j<maxn;j++)
        nok[j]=((j<<2)&(j)) || ((j<<1)&(j));

    for(i=0;i<maxn;i++){
        if(nok[i]) continue;
        for(j=2;j<n+2;j++)
            if((map[j]&i)==i)
                ok[j][tot[j]++]=i;
    }
    for(i=0;i<n;i++)
        for(J=0;J<tot[i+2];J++){
            j=ok[i+2][J];
            for(K=0;K<tot[i+1];K++){
                k=ok[i+1][K];
                if(j&k) continue;
                for(L=0;L<tot[i];L++){
                    l=ok[i][L];
                    if((l&k)||(l&j)) continue;
                    if(dp[i][K][L]+sum[j]>dp[i+1][J][K]){
                        dp[i+1][J][K]=dp[i][K][L]+sum[j];
                        if(dp[i+1][J][K]>ans) ans=dp[i+1][J][K];
                    }
                }
            }
        }
    printf("%d\n",ans);
}