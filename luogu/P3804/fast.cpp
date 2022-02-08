#include <bits/stdc++.h>
using namespace std;
int tot=1,las=1;
struct NODE
{
    int ch[26];
    int len,fa;
    NODE(){memset(ch,0,sizeof(ch));len=fa=0;}
}dian[2000010];
vector<int> to[2000010];
void jia(int a,int b)
{
	to[a].push_back(b);
}
long long zhi[2000010];
inline void add(int c)
{
    int p=las,np=las=++tot;zhi[tot]=1;
    dian[np].len=dian[p].len+1;
    for(;p&&!dian[p].ch[c];p=dian[p].fa)dian[p].ch[c]=np;
    if(!p)dian[np].fa=1;
    else
    {
        int q=dian[p].ch[c];
        if(dian[q].len==dian[p].len+1)dian[np].fa=q;
        else
        {
            int nq=++tot;
            dian[nq]=dian[q];dian[nq].len=dian[p].len+1;
            dian[q].fa=dian[np].fa=nq;
            for(;p&&dian[p].ch[c]==q;p=dian[p].fa)dian[p].ch[c]=nq;
        }
    }
}
char s[2000010];
int cd;
long long ans=0;
void dfs(int node)
{
    for(auto y: to[node])
    {
        dfs(y);
        zhi[node]+=zhi[y];
    }
    if(zhi[node]!=1)ans=max(ans,zhi[node]*dian[node].len);
}
int main()
{
    scanf("%s",s);cd=strlen(s);
    for(int i=0;i<cd;i++)add(s[i]-'a');
    for(int i=2;i<=tot;i++)jia(dian[i].fa,i);
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}
