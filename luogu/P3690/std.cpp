#include<bits/stdc++.h>
using namespace std;
const int N=3e5+9;
inline int in(){
	int x;
	scanf("%d", &x);
	return x;
}
int f[N],c[N][2],v[N],s[N],st[N];
bool r[N];
inline bool nroot(int x){
	return c[f[x]][0]==x||c[f[x]][1]==x;
}
void pushup(int x){
	s[x]=s[c[x][0]]^s[c[x][1]]^v[x];
}
void pushr(int x){int t=c[x][0];c[x][0]=c[x][1];c[x][1]=t;r[x]^=1;}
void pushdown(int x){
	if(r[x]){
		if(c[x][0])pushr(c[x][0]);
		if(c[x][1])pushr(c[x][1]);
		r[x]=0;
	}
}
void rotate(int x){
	int y=f[x],z=f[y],k=c[y][1]==x,w=c[x][!k];
	if(nroot(y))c[z][c[z][1]==y]=x;c[x][!k]=y;c[y][k]=w;
	if(w)f[w]=y;f[y]=x;f[x]=z;
	pushup(y);
}
void splay(int x){
	int y=x,z=0;
	st[++z]=y;
	while(nroot(y))st[++z]=y=f[y];
	while(z)pushdown(st[z--]);
	while(nroot(x)){
		y=f[x];z=f[y];
		if(nroot(y))
			rotate((c[y][0]==x)^(c[z][0]==y)?x:y);
		rotate(x);
	}
	pushup(x);
}
void access(int x){
	for(int y=0;x;x=f[y=x])
		splay(x),c[x][1]=y,pushup(x);
}
void makeroot(int x){
	access(x);splay(x);
	pushr(x);
}
int findroot(int x){
	access(x);splay(x);
	while(c[x][0])pushdown(x),x=c[x][0];
	splay(x);
	return x;
}
void split(int x,int y){
	makeroot(x);
	access(y);splay(y);
}
void link(int x,int y){
	makeroot(x);
	if(findroot(y)!=x)f[x]=y;
}
void cut(int x,int y){
	makeroot(x);
	if(findroot(y)==x&&f[y]==x&&!c[y][0]){
		f[y]=c[x][1]=0;
		pushup(x);
	}
}
int main()
{
	int n=in(),m=in();
	for(int i=1;i<=n;++i)v[i]=in();
	while(m--){
		int type=in(),x=in(),y=in();
		switch(type){
		case 0:split(x,y);printf("%d\n",s[y]);break;
		case 1:link(x,y);break;
		case 2:cut(x,y);break;
		case 3:splay(x);v[x]=y;
		}
	}
	return 0;
}
