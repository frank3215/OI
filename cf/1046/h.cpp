#include <cstdio>
#include <set>
#include <map>
#include <cstring>
#include <cctype>
const int maxn=2e6;
int n,ss[maxn],c[27],l,cur=0;
long long ans;
char s[maxn],fin[maxn];
std::map<int,int> m;
char gc(){
	return fin[cur++];
}
void get(int &a){
	char c;
	while(isspace(c=gc()));
	a=0;
	do{
//		printf("%d",c);
		a=a*10+c-'0';
	}while(!isspace(c=gc()));
}
void get(char *s){
	char c;
	while(isspace(c=gc()));
	do{
		*(s++)=c;
	}while(!isspace(c=gc()));
	*s='\0';
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		memset(c,0,sizeof(c));
		l=strlen(s);
		for(int j=0;j<l;j++)
			c[s[j]-'a']++;
		for(int j=0;j<26;j++)
			ss[i]^=(c[j]%2)<<j;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<26;j++)
			ans+=m[ss[i]^(1<<j)];
		ans+=m[ss[i]]++;
//		m.insert(ss[i]);
	}
	printf("%I64d\n",ans);
}
