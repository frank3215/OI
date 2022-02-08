/*
ID: chengef2
TASK: barn1
PROG: barn1
LANG: C++                 
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#define IO(s) ofstream fout ( s ".out" ); ifstream fin ( s ".in" );

using namespace std;

const int maxs = 210;
int m, s, c, a[maxs], d[maxs], ans;

int main() {
	IO("barn1");
	fin >> m >> s >> c;
	for (int i=1; i<=c; ++i) {
		fin >> a[i];
	}
	sort(a+1, a+1+c);
	for (int i=1; i<=c; ++i) {
		d[i-1] = a[i] - a[i-1] - 1;
	}
	ans = a[c] - a[1] + 1;
	sort(d+1, d+c, greater<int>());
	for (int i=1; i<c && i<m; ++i) {
		ans -= d[i];
	}
	fout << ans << endl;
}
