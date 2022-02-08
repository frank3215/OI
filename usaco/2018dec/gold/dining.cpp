#include <cstdio>
#include <cstring>
#include <queue>
const int maxn = 5e4 + 10;
int n,m,k;
int hay[maxn];
int dis[2][maxn];
std::vector<std::pair<int,int> > v[maxn];
struct node{
	int dis,cur;
	int hay;
	bool operator <(const node &d) const{
		return dis > d.dis;
	}
};
void dijkstra() {
	std::priority_queue <node> q;
	q.push((node){0, n, hay[n]});
	dis[0][n] = dis[1][n] = 0;
	while (!q.empty()) {
		node d = q.top(); q.pop();
		for (int i=0; i<v[d.cur].size(); ++i) {
			std::pair<int,int> vv = v[d.cur][i];
			int to = vv.first, cost = vv.second;
			if (!d.hay) {
				if (dis[0][to] > d.dis + cost) {
					dis[0][to] = d.dis + cost;
					q.push((node){dis[0][to], to, 0});
				}
				if (hay[to] && dis[1][to] > d.dis + cost - hay[to]) {
					dis[1][to] = d.dis + cost - hay[to];
					q.push((node){dis[1][to], to, hay[to]});
				}
			}
			else {
				if (dis[1][to] > d.dis + cost) {
					dis[1][to] = d.dis + cost;
					q.push((node){dis[1][to], to, d.hay});
				}
				if (hay[to] && dis[1][to] > d.dis + cost + d.hay - hay[to]) {
					dis[1][to] = d.dis + cost + d.hay - hay[to];
					q.push((node){dis[1][to], to, hay[to]});
				}
			}
		}
	}
}

int main() {
	freopen("dining.in","r",stdin);
	freopen("dining.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	while (m--) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v[a].push_back(std::make_pair(b,c));
		v[b].push_back(std::make_pair(a,c));
	}
	while (k--) {
		int p,y;
		scanf("%d%d",&p,&y);
		if (y > hay[p]) hay[p] = y;
	}
	memset(dis,0x3f,sizeof(dis));
	dijkstra();
	for (int i=1; i<n; ++i) {
		printf("%d\n",dis[0][i] >= dis[1][i]);
//		printf("%d %d\n",dis[0][i],dis[1][i]);
	}
}
