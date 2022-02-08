#include <bits/stdc++.h>
using namespace std;

const int B = 127, maxn = 1e5+10, maxl = 1e6+10;

unsigned long long powb[maxl]={1};

struct str{
	string s;
	vector<unsigned long long> v;
	void init(string &t) {
		v.clear();
		s = t;
		v.push_back(0);
		for (int i = 0; i < (int)s.size(); ++i) {
			v.push_back(v.back()*B + (int)s[i]);
		}
	}
	void operator += (const str &S) {
		int l = 0, r = min(s.size(), S.s.size());
		while (l < r) {
			int m = (l+r+1)>>1;
			if (v.back()-v[(int)s.size()-m]*powb[m] == S.v[m]) l = m;
			else r = m-1;
		}
		long long tmp = v.back();
		for (int i = l; i < S.s.size(); ++i) {
			s += S.s[i];
			v.push_back(v.back()*B + (int)S.s[i]);
		}
	}
	void print() {
		cout << "PRINT: " << s << endl;
		cout << "     :";
		for (int i = 0; i < (int)v.size(); ++i)
			cout << ' ' << v[i];
		cout << endl;
	}
}a, b;

int main() {
	int n;
	for (int i = 1; i < maxl; ++i) powb[i] = powb[i-1]*B;
	cin >> n;
	string s;
	a.init(s);
	for (int i = 0; i < n; ++i) {
		cin >> s;
		b.init(s);
		a.print();
		b.print();
		a += b;
		cout << a.s << endl;
	}
	cout << a.s;
}
