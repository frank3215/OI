#include <bits/stdc++.h>
using namespace std;

int main() {
	FILE *fin, *fout;
	for (int n = 1; n <= 10; ++n) {
		for (int m = 1; m <= 10; ++m) {
			fin = fopen("input", "w");
			fprintf(fin, "%d %d\n", n, m);
			fflush(fin);
			fclose(fin);

			system("./b < input > output");

			int x, y, px, py;
			vector<vector<bool> > v(n, vector<bool>(m, false));
			set<pair<int, int> > s;
			fout = fopen("output", "r");
			fscanf(fout, "%d%d", &px, &py);
			assert(px == 1 && py == 1);
			v[0][0] = 1;
			while (fscanf(fout, "%d%d", &x, &y) == 2) {
				assert(s.find(make_pair(x-px, y-py)) == s.end());
				assert(v[x-1][y-1] == 0);
				v[x-1][y-1] = 1;
				px = x, py = y;
			}
			fclose(fout);
		}
	}
}
