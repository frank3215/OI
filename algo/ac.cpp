#include 
#include 
#define m 10000
int son[m][26],n,tot,l,cur,rt,fail[m],i,j;
char s[m];
int find(int cur,int i){
	if(cur==0) return rt;
	if(son[cur][i]) return son[cur][i];
	son[cur][i]=find(fail[cur],i);
}
int main(){
	scanf("%d",&n);
	cur=rt=1;
	memset(son,0,sizeof(son));
	for(i=0;i<n;i++){
		scanf("%s",s);
		l=strlen(s);
		for(j=1,cur=rt;i<l;i++){
			if(!son[cur][s[i]-'a'])
				son[cur][s[i]-'a']=++tot;
			cur=son[cur][s[i]-'a'];
		}
		end[cur]=i;
	}
	for(q[l=r=1]=rt;l<=r;l++){
		for(i=0;i<26;i++)
			if(son[q[l]][i]){
				fail[son[q[l]][i]]=find(fail[q[l]],i);
				q[++r]=son[q[l]][i];
			}
	}
	scanf("%s",s);
	m=strlen(s);
	for(i=1,cur=rt;i<=m;i++)
		cur=find(cur,s[i]-'a'),vis[cur]++;
	for(i=r;i>=1;i--){
		vis[fail[q[i]]]+=vis[q[i]];
		if(end[q[i]]) ans[end[q[i]]]=vis[q[i]];
	}
	for(i=1;i<=n;i++)
}