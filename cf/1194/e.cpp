#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;

int n;
int X1[maxn], X2[maxn], Y1[maxn], Y2[maxn];
long long ans;
vector<pair<int, int> > vx, vy, v;

//树状数组
int t[maxn];
void add(int x) {
	x += 5002;
	for (; x < maxn; x += x&-x) t[x]++;
}
int query(int x) {
	x += 5002;
	int res = 0;
	for (; x; x -= x&-x) res+=t[x];
	return res;
}
int query(int x, int y) {
	int res = query(y) - query(x-1);
	return res*(res-1)/2;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d%d%d%d", X1+i, Y1+i, X2+i, Y2+i);
		if (X1[i] > X2[i]) swap(X1[i], X2[i]);
		if (Y1[i] > Y2[i]) swap(Y1[i], Y2[i]);

		if (X1[i] == X2[i]) vx.push_back(make_pair(X1[i], i));
		else vy.push_back(make_pair(Y1[i], i));
	}
	sort(vx.begin(), vx.end());
	sort(vy.begin(), vy.end());

	for (int I = 0; I < vy.size(); ++I) {
		int i = vy[I].second;

		memset(t, 0, sizeof(t));
		v.clear();

		for (int K = 0; K < vx.size(); ++K) {
			int k = vx[K].second;
			if (Y2[k] >= Y1[i]) //竖直线段k与水平线段i有交点。
				v.push_back(make_pair(Y1[k], k));
		}

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for (int J = 0; J < I; ++J) { //枚举与i构成矩形的水平线段j
			int j = vy[J].second;
			while (!v.empty() && v.back().first <= Y1[j]) {
				add(X1[v.back().second]);
				v.pop_back();
			}
			int xx1 = max(X1[i], X1[j]), xx2 = min(X2[i], X2[j]); //求两个线段的交。
			if (xx1 < xx2) ans += query(xx1, xx2);
		}
	}
	printf("%lld\n", ans);
}
