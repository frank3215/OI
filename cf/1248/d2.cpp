#include <bits/stdc++.h>
using namespace std;

const char *par = "()";
const int pm[] = {1, -1};
#define corr(x) pm[strchr(par, x)-par]

int n;
int mn, res, fir;
string s;
vector<int> v, w;
map<int, int> mp;

int init(string s) {
	v = vector<int>(n);
	for (int i = 0, pre = 0; i < n; ++i) {
		v[i] = (pre += corr(s[i]));
		mp[v[i]]++;
	}
	if (v.back() != 0) return 0;

	res = mp.begin()->second;
	mn = mp.begin()->first;
	for (int i = 0; i < n; ++i)
		if (v[i] == mn) {
			fir = (i+1)%n;
			return res;
		}
}

int count(int l, int r) {
	int cur = v[(l-1+n)%n];
	s[l] = ')';
	for (int i = l; i != r; i=(i+1)%n) {
		cur += corr(s[i]);
		if (!--mp[v[i]]) mp.erase(v[i]);
		mp[cur]++;
	}
	int ret = mp.begin()->second;
	cur = v[(l-1+n)%n];
	for (int i = l; i != r; i=(i+1)%n) {
		cur += corr(s[i]);
		if (!--mp[cur]) mp.erase(cur);
		mp[v[i]]++;
	}
	s[l] = '(';
	return ret;
}

int main() {
	cin >> n >> s;
	if (!init(s)) {
		cout << "0\n1 1\n";
		return 0;
	}
	stack<int> st;
	int i = fir;
	w = vector<int>(n);
	do {
		if (s[i] == '(') st.push(i);
		if (s[i] == ')') {
			w[i] = st.top();
			w[w[i]] = i;
			st.pop();
		}
	} while ((i=(i+1)%n) != fir);
	int ans[3] = {res};
	for (int i = 0; i < n; ++i) if (s[i] == '(' && v[i] <= mn+2) {
		int ret = count(i, w[i]);
		if (ret > ans[0])
			ans[0] = ret, ans[1] = i, ans[2] = w[i];
	}
	cout << ans[0] << endl << ans[1]+1 << ' ' << ans[2]+1 << endl;
}
