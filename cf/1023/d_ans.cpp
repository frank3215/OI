#include<cstdio>
const int maxn=200010;
int n,q,a[maxn],l[maxn],r[maxn],fa[maxn];
int find(int i){return fa[i]==i?i:fa[i]=find(fa[i]);}
void cmin(int&a,int b){b<a?a=b:1;}
void cmax(int&a,int b){b>a?a=b:1;}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<=q;i++)l[i]=n,r[i]=0;
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
		cmin(l[a[i]],i);
		cmax(r[a[i]],i);
	}
	for(int i=1;i<=n;i++)fa[i]=i;
	if(l[q]>r[q]){
		if(l[0]>r[0]){
			puts("NO");
			return 0;
		}
		a[l[0]]=q;
		fa[l[0]]=find(l[0]+1);
	}
	for(int i=q;i;i--){
		for(int j=find(l[i]);j<=r[i];j=find(j)){
			if(a[j]&&a[j]<i){
				puts("NO");
				return 0;
			}
			a[j]=i;
			fa[j]=find(j+1);
			//解说：注意这里是从q到1的,每次都跳过之前设置过的数知道右端点.
		}
	}
	puts("YES");
	for(int i=0;i<n;i++)printf("%d%c",a[i]?a[i]:1," \n"[i==n-1]);
}
