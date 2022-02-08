#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5, maxa = 2e5, maxlogkn = 60;

int N, a[maxn];
long long K, nxt[maxlogkn][maxn];
vector<int> occur[maxa+1];
set<int> s;
vector<int> vs;

int main() {
	cin >> N >> K;
	K *= N;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		occur[A[i]].push_back(i);
	}
	for (int i = 0; i <= maxa; ++i)
		if (occur[i].size()) {
			occur[i].push_back(occur.front()+N);
			for (int j = 1; j < occur[i].size(); ++j)
				nxt[0][occur[i][j-1]] = occur[i][j]-occur[i][j-1]+1;
		}
	for (int w = 1; w < maxlogkn; ++w) {
		for (int i = 0; i < N; ++i) {
			int tmp = (i+nxt[w-1][i])%N;
			nxt[w][i] = nxt[w-1][i]+nxt[w-1][tmp];
		}
	}
	long long pre = 0; int pos = 0;
	for (int w = maxlogkn-1; ~w; --w)
		if (pre+nxt[w][pos] < K) {
			pre += nxt[w][pos];
			pos = (pos+nxt[w][pos])%N;
		}
	for (long long cur = pos; cur < K; ++cur) {
		int val = val;
		if (s.count(A[val])) {
			while (s.count(val)) {
				s.erase(v.back());
				v.pop_back();
			}
		}
		else {
			v.push_back(val);
			s.add(val);
		}
	}
	for (int i = 0; i < v.size(); ++i) {
		printf("%d ", v[i]);
	}
}
