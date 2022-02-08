/*
ID: chengef2
TASK: crypt1
PROG: crypt1.cpp
LANG: C++                 
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#define IO(s) std::ofstream fout ( s ".out"); std::ifstream fin ( s ".in");
#define cIO(s) FILE *fout = fopen( s ".out", "w"), *fin = fopen(s ".in", "r");

int n, t, ans;
int a[10]={ };

bool ok(int x) {
	if (x>=10000) return false;
	for ( ; x; x/=10) if (!a[x%10]) return false;
	return true;
}

bool ok(int x, int y) {
	for ( ; x; x/=10) if ( x%10*y>=1000 || !ok(x%10*y) ) return false;
	return true;
}
int main( ) {
	IO("crypt1");

	fin >> n;
	for (int i=0; i<n; ++i) {
		fin >> t;
		a[t] = 1;
	}
	for (int i=10; i<100; ++i) if (ok(i)) {
		for (int j=100; j<1000; ++j) if (ok(j)) {
			if ( ok(i*j) && ok(i,j) ) {
				++ans;
			}
		}
	}
	fout << ans << std::endl;
	return -0;
}
