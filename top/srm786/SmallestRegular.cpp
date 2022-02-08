#include <bits/stdc++.h>
using namespace std;

class SmallestRegular{
public:
	vector <int> findLexSmallest(string s) {
		vector<int> ret;
#define pb push_back
		for (int i = 0; i < (int)s.size(); ++i) {
			if (s[i] == '(' && i) {
				ret.pb(0);
				ret.pb(i-1);
				ret.pb(i);
			}
		}
		return ret;
	}
};

int main() {
	string s;
	cin >> s;
	vector<int> v = SmallestRegular().findLexSmallest(s);
	for (auto x : v) cout << x << endl;
}
