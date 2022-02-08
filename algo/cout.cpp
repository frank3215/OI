#include <cstdio>
const int maxn=2e8;
int x,l=0;
char s[maxn];
FILE *fout = fopen("c.out","w");
inline int pc(const char c=0){
	return (l==maxn||!c)&&(l=(l!=fwrite(s,l,1,fout)))?EOF:s[l++]=c;
}
/*inline void write(int x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) write(x/10);
	putchar(x%10+'0');
}*/
void write(int x,const char c){
	//if(x==0){s[l++](48);return;}
	int len=0,s=0;
	char dg[20]={c};
	if((s=x<0)) x=-x;
	do{dg[++len]=48+x%10;x/=10;}while(x);
	if(s) dg[++len]='-';
	for(int i=len;i>=0&&dg[i]>0;i--) pc(dg[i]);
}
/*void write(long long x){
	long long y=10,len=1;
	while(y<=x)	{y*=10;len++;}
	while(len--){y/=10;s[l++]=x/y+'0';x%=y;}
	s[l++]='\n';
}*/
int main(){
	//freopen("c.in","r",stdin);
	scanf("%d",&x);
	for(long long i=x;i>0;i=(i-1)&x)
		write(i,'\n');
	write(0,'\n');
	pc();
	//fwrite(s, l, 1, fout);
}
