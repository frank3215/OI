#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> p, q;
set<vector<int> > st;

int main() {
	scanf("%d%d", &n, &k);
	p = vector<int>(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &p[i]);
	for (int i = 0; i+k<=n; ++i) {
		q = p;
		sort(q.begin()+i, q.begin()+i+k);
		st.insert(q);
	}
	printf("%lu\n", st.size());
}
