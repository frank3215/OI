#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

int n, b[N+1], mu[N+1], cur[N+1];
vector<int> f[N+1];

bool check(int x) {
	int sum = 0;
	for (auto i : f[x]) sum += mu[i]*cur[i];
	return sum;
}
void modify(int x, int k) {
	for (auto i : f[x]) cur[i] += k;
}

int main() {
	for (int i = 1; i <= N; ++i) mu[i] = 1;
	for (int i = 1; i <= N; ++i) {
		if (f[i].size() == 1) {
			for (int j = i; j <= N; j += i)
				mu[j] *= (-1)*(j%(i*i)!=0);
		}
		for (int j = i; j <= N; j += i)
			f[j].push_back(i);
	}

	cin >> n;
	int a;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		for (auto j : f[a]) b[j] = 1;
	}
	stack<int> s;
	long long ans = 1; //prev: 0
	for (int i = N; i; --i) if (b[i]) {
		int lst = 0;
		while (!s.empty() && check(i)) {
			lst = s.top();
			modify(s.top(), -1);
			s.pop();
		}
		ans = max(ans, 1ll*lst*i);
		s.push(i);
		modify(i, 1);
	}
	cout << ans << endl;
}
