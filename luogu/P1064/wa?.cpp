#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int f[5000010],h[5000010];
struct node
{
    int v,p,q;
}a[1010];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a[i].v,&a[i].p,&a[i].q);
        a[i].p*=a[i].v;
    }
    for(int i=1;i<=m;i++)
        if(!a[i].q)
        {
            for(int j=1;j<a[i].v;j++)
                h[j]=0;//最好是-inf吧 
            for(int j=a[i].v;j<=n;j++)
                h[j]=f[j-a[i].v]+a[i].p;
            for(int j=1;j<=m;j++)
                if(a[j].q==i)
                    for(int k=n;k>=a[i].v+a[j].v;k--)
                        h[k]=max(h[k],h[k-a[j].v]+a[j].p);
            for(int j=a[i].v;j<=n;j++)
                f[j]=max(f[j],h[j]);
        }   
    printf("%d\n",f[n]);
    return 0;
}
