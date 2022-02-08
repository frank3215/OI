#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
#define RI register int
#define A printf("A")
#define C printf(" ") 
using namespace std;
const int N=3e5+2;
int f[N],v[N],s[N],r[N],hep[N],ch[N][2];
inline int get(int x){
    return ch[f[x]][0]==x||ch[f[x]][1]==x;
}
inline void pushup(int x){
    s[x]=s[ch[x][1]]^s[ch[x][0]]^v[x];
}
inline void filp(int x){
    r[x]^=1;
} 
inline void pushdown(int x){
    if(!r[x])return;
	swap(ch[x][0], ch[x][1]);
    if(ch[x][0])filp(ch[x][0]);
    if(ch[x][1])filp(ch[x][1]);
	r[x]=0;
} 
inline void rotate(int x){
    int y=f[x],z=f[y],k=ch[y][1]==x,v=ch[x][!k]; 
    if(get(y))ch[z][ch[z][1]==y]=x;
	ch[x][!k]=y,ch[y][k]=v;
    if(v)f[v]=y;
	f[y]=x,f[x]=z;
	pushup(y),pushup(x);
}
inline void Splay(int x){
    int y=x,top=0;hep[++top]=y;
    while(get(y))hep[++top]=y=f[y];
    while(top)pushdown(hep[top--]);
    while(get(x)){
        y=f[x],top=f[y];
        if(get(y))
           rotate((ch[y][0]==x)^(ch[top][0]==y)?x:y);
        rotate(x);
    }
}
inline void Access(int x){
    for(register int y=0;x;x=f[y=x])
       Splay(x),ch[x][1]=y,pushup(x);
}
inline void makeroot(int x){
    Access(x);Splay(x);filp(x);
}
inline int findroot(int x){
    Access(x);Splay(x);
    while(pushdown(x),ch[x][0]) x=ch[x][0];
    return x;
}
inline void split(int x,int y){
    makeroot(x);Access(y);Splay(y);
} 
inline void link(int x,int y){
    makeroot(x);if(findroot(y)!=x)f[x]=y;
}
inline void cut(int x,int y){
    split(x,y);
    if(findroot(y)==x&&f[x]==y&&!ch[x][1]){
        f[x]=ch[y][0]=0;pushup(y);
    }
}int n,m,x,y,op;
int main(){
    scanf("%d%d",&n,&m);
    for(register int i=1;i<=n;++i)scanf("%d",&v[i]); 
    for(register int i=1;i<=m;++i){
        scanf("%d%d%d",&op,&x,&y);
        if(op==0)split(x,y),printf("%d\n",s[y]);
        else if(op==1)link(x,y);
        else if(op==2)cut(x,y);
        else Splay(x),v[x]=y;
    }return 0;
}
