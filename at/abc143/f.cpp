#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5+10;

int n, a, cnt[maxn], ccnt[maxn], len, cur, ans, tot, i, sum;

int main() {
	cin >> n;
	for (i = 0; i < n; ++i) {
		cin >> a;
		cnt[a]++;
	}
	for (i = 1; i <= n; ++i) ccnt[cnt[i]]++;
	for (cur = 1, ans = n+1; cur <= n; ++cur) {
		while (ans && tot < cur && (n-sum)/(cur-tot) < ans) {
			ans--;
			tot += ccnt[ans];
			sum += ccnt[ans]*ans;
		}
		cout << ans << endl;
	}
}
