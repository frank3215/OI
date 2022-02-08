#include <cstdio>
#include <cstring>
#include <algorithm>
const int maxn = 50010;
const int weight[]={1,-1};
int n, ice[maxn][5], tot;
long long ans = 0;
struct selection{
	int tot,a[5];
	bool operator <(const selection &s) const {
		return memcmp(a,s.a,sizeof(a)) < 0;
	}
	void print(){
		printf("%d:",tot);
		for (int i=0; i<tot; ++i) printf(" %d",a[i]);
		putchar('\n');
	}
}list[maxn*32];
int main() {
	freopen("cowpatibility.in","r",stdin);
	freopen("cowpatibility.out","w",stdout);
	scanf("%d",&n);
	ans = (long long)n*(n-1)/2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			scanf("%d",&ice[i][j]);
		}
		std::sort(ice[i], ice[i]+5);
		for (int j = 1; j < 32; ++j) {
			selection &cur = list[tot++];
			for (int l = j, k = 0; k < 5; ++k, l >>= 1) {
				if (l&1) cur.a[cur.tot++] = ice[i][k];
			}
//			cur.print();
		}
	}
	std::sort(list, list+tot);
	for (int i = 0; i < tot;) {
		int j = i;
		while (j < tot && !(list[i] < list[++j]));
		ans += (j-i-1ll)*(j-i)/2*weight[list[i].tot&1];
//		printf("%d %d %d\n ",i,j,ans);
//		list[i].print();
		i=j;
	}
	printf("%lld\n", ans);
}
