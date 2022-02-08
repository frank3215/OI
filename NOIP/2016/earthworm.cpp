#include <cstdio>
#include <queue>
using namespace std;
int main()
{
    int n,m,q,u,v,t,x,a,b,i;
    long long adjust=0;
    priority_queue<long long,vector<long long>,less<long long> > que;
    scanf("%d%d%d%d%d%d",&n,&m,&q,&u,&v,&t);
    for(i=0;i<n;i++){
        scanf("%d",&x);
        que.push(x);
    }
    for(i=1;i<=m;i++){
        x=que.top();que.pop();
        if(i%t==0) printf("%lld ",x+adjust);
        a=(x+adjust)*u/v;b=(x+adjust)-a;
        adjust+=q;
        que.push(a-adjust);que.push(b-adjust);
    }printf("\n");
    for(i=1;i<=m+n;i++){
        x=que.top();que.pop();
        if(i%t==0) printf("%lld ",x+adjust);
    }printf("\n");
    return 0;
}