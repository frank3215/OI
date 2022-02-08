#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

const int maxn = 2019;

int t, n, k, cnt;
char s[maxn];
vector<pair<int,int> > op;

void sadd() {
	for (int i = 0; i < n; ++i) {
	}
}

void solve() {
	scanf("%d%d%s", &n, &k, s);
	op.clear();
	for (int i = 0; i < n; i += 2) {
		if (s[i] == '(') {
			for (int j = i+1; j < n; ++j) {
				if (s[j] == ')') {
					reverse(s+i+1, s+j+1);
					op.push_back(make_pair(i+2, j+1));
					break;
				}
			}
		}
		if (s[i] == ')') {
			for (int j = i+1; j < n; ++j) {
				if (s[j] == '(') {
					reverse(s+i, s+j+1);
					op.push_back(make_pair(i+1, j+1));
					break;
				}
			}
		}
	}
	for (int i = n/2; i > k; --i) {
		op.push_back(make_pair(2*i-2, 2*i-1));
	}
	printf("%d\n", (int)op.size());
	for (int i = 0; i < (int)op.size(); ++i)
		printf("%d %d\n", op[i].first, op[i].second);
}

int main() {
	scanf("%d", &t);
	while (t--) solve();
}
