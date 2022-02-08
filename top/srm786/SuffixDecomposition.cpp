#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;

class SuffixDecomposition {
	public:
	long long findTotalFun(vector <int> P, int A0, int X, int Y, int B0, int X1, int Y1, int N) {
		vector<int> a(N), b(N), s = P;
		int n = N;
		a[0] = A0, b[0] = B0;
		for (int i = 1; i < n; ++i) {
			a[i] = ((long long)a[i-1] * X + Y) % 1812447359;
			b[i] = ((long long)b[i-1] * X1 + Y1) % 1812447359;
		}
		for (int i = (int)P.size(); i < n; ++i) {
			s.push_back(max(a[i], b[i]));
		}
		deque<pair<int, int> > q;
		long long ans = 0;
		for (int i = n-1; ~i; --i) {
			int mn = s[i], mx = s[i];
			while (!q.empty() && q.front().first <= mx) {
				mn = min(mn, q.front().first);
				mx = max(mx, q.front().second);
                q.pop_front();
			}
			q.push_front(make_pair(mn, mx));
			ans += q.size();
            printf("%d\n", (int)q.size());
            for (int i = 0; i < (int)q.size(); ++i) {
                printf("(%d %d)\n", q[i].first, q[i].second);
			}
		}
		return ans;
	}
};

