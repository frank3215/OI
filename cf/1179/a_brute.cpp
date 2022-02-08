#include <bits/stdc++.h>
using namespace std;

int N, Q;
deque<int> p, q;

int main() {
	scanf("%d%d", &N, &Q);
	int a, b;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a);
		p.push_back(a);
	}
	int m;
	while (Q--) {
		scanf("%d", &m);
		q = p;
		while (m--) {
			a = q.front(); q.pop_front();
			b = q.front(); q.pop_front();
			if (!m) {
				printf("%d %d\n", a, b);
			}
			if (a > b) {
				q.push_front(a);
				q.push_back(b);
			}
			else {
				q.push_front(b);
				q.push_back(a);
			}
		}
	}
}
