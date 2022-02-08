#include <iostream>

using namespace std;

int t, w, r[7], res;
long long ans;

int main() {
	cin >> t >> w;
	while (t--) {
		cout << 224 << endl;
		cin >> ans;
//		fprintf(stderr, "%llx\n", ans);
		for (int i = 4; i <= 6; ++i) r[i] = ans>>(224/i)&((1<<7)-1);
		cout << 56 << endl;
		cin >> ans;
//		fprintf(stderr, "%llx\n", ans);
		for (int i = 1; i <= 2; ++i) {
			r[i] = ans>>(56/i)&((1<<7)-1);
			ans -= (long long)r[i]<<(56/i);
		}
		for (int i = 4; i <= 5; ++i) ans -= r[i]<<(56/i);
		r[3] = ans>>(56/3);
		for (int i = 1; i <= 6; ++i) cout << r[i] << ' ';
		cout << endl;
		cin >> res;
		if (res == -1) break;
	}
}
