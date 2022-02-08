//minamoto
#include<iostream>
#include<cstdio>
#include<algorithm>
#define swap(x,y) (x^=y,y^=x,x^=y)
#define mul(x,y) (1ll*x*y%P)
#define add(x,y) (x+y>=P?x+y-P:x+y)
#define dec(x,y) (x-y<0?x-y+P:x-y)
using namespace std;
#define getc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int read(){
    #define num ch-'0'
    char ch;bool flag=0;int res;
    while(!isdigit(ch=getc()))
    (ch=='-')&&(flag=true);
    for(res=num;isdigit(ch=getc());res=res*10+num);
    (flag)&&(res=-res);
    #undef num
    return res;
}
char sr[1<<21],z[20];int K=-1,Z;
inline void Ot(){fwrite(sr,1,K+1,stdout),K=-1;}
inline void print(int x){
    if(K>1<<20)Ot();if(x<0)sr[++K]=45,x=-x;
    while(z[++Z]=x%10+48,x/=10);
    while(sr[++K]=z[Z],--Z);sr[++K]=' ';
}
const int N=500005,P=998244353;
inline int ksm(int a,int b){
    int res=1;
    while(b){
        if(b&1) res=mul(res,a);
        a=mul(a,a),b>>=1;
    }
    return res;
}
int n,r[N],A[N],B[N],C[N],D[N],F[N],G[N],O[N],f[N],g[N],inv[N];
void init(int limit){
    for(int i=0,l=limit<<1;i<=l;++i) inv[i]=ksm(i,P-2);
}
void NTT(int *A,int type,int len){
    int limit=1,l=0;
    while(limit<len) limit<<=1,++l;
    for(int i=0;i<limit;++i)
    r[i]=(r[i>>1]>>1)|((i&1)<<(l-1));
    for(int i=0;i<limit;++i)
    if(i<r[i]) swap(A[i],A[r[i]]);
    for(int mid=1;mid<limit;mid<<=1){
        int R=mid<<1,Wn=ksm(3,(P-1)/R);O[0]=1;
        for(int j=1;j<mid;++j) O[j]=mul(O[j-1],Wn);
        for(int j=0;j<limit;j+=R){
            for(int k=0;k<mid;++k){
                int x=A[j+k],y=mul(O[k],A[j+k+mid]);
                A[j+k]=add(x,y),A[j+k+mid]=dec(x,y);
            }
        }
    }
    if(type==-1){
        reverse(A+1,A+limit);
        for(int i=0,invl=inv[limit];i<limit;++i)
        A[i]=mul(A[i],invl);
    }
}
void Inv(int *a,int *b,int len){
    if(len==1) return (void)(b[0]=inv[a[0]]);
    Inv(a,b,len>>1);
    for(int i=0;i<len;++i) C[i]=a[i],D[i]=b[i];
    NTT(C,1,len<<1),NTT(D,1,len<<1);
    for(int i=0,l=(len<<1);i<l;++i) C[i]=mul(mul(C[i],D[i]),D[i]);
    NTT(C,-1,len<<1);
    for(int i=0;i<len;++i) b[i]=dec(add(b[i],b[i]),C[i]);
    for(int i=0,l=(len<<1);i<l;++i) C[i]=D[i]=0;
}
void Direv(int *A,int *B,int len){
    for(int i=1;i<len;++i) B[i-1]=mul(A[i],i);B[len-1]=0; 
}
void Inter(int *A,int *B,int len){
    for(int i=1;i<len;++i) B[i]=mul(A[i-1],inv[i]);B[0]=0; 
}
void Ln(int *a,int *b,int len){
    Direv(a,A,len),Inv(a,B,len);
    NTT(A,1,len<<1),NTT(B,1,len<<1);
    for(int i=0,l=len<<1;i<l;++i) A[i]=mul(A[i],B[i]);
    NTT(A,-1,len<<1),Inter(A,b,len<<1);
    for(int i=0,l=len<<1;i<l;++i) A[i]=B[i]=0;
}
void Exp(int *a,int *b,int len){
    if(len==1) return (void)(b[0]=1);
    Exp(a,b,len>>1),Ln(b,F,len);
    F[0]=dec(a[0]+1,F[0]);
    for(int i=1;i<len;++i) F[i]=dec(a[i],F[i]);
    NTT(F,1,len<<1),NTT(b,1,len<<1);
    for(int i=0,l=len<<1;i<l;++i) b[i]=mul(b[i],F[i]);
    NTT(b,-1,len<<1);
    for(int i=len,l=(len<<1);i<l;++i) b[i]=F[i]=0;
}
int main(){
//  freopen("testdata.in","r",stdin);
    n=read();
    for(int i=0;i<n;++i) f[i]=read();
    int len;for(len=1;len<=n;len<<=1);init(len);
    Exp(f,g,len);
    for(int i=0;i<n;++i) print(g[i]);
    Ot();
    return 0;
}
