#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 100;
	printf("%d\n", t);
	while (t--) {
		int n = 7;
		printf("%d\n", n);
		set<pair<int,int> > s;
		while (n--) {
			int x, y;
			do {
				x = rand()%10, y = rand()%10;
			} while (s.count(make_pair(x, y)));
			printf("%d %d\n", x, y);
			s.insert(make_pair(x, y));
		}
	}
}
