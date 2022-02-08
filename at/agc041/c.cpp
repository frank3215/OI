#include <bits/stdc++.h>
#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define F0R(i,b) FOR(i,0,b)
using namespace std;

const int maxn = 1010;

const char ans[5][7][8] = {
	{
		{"add"},
		{"a.c"},
		{"bbc"},
	},
	{
		{"fhdd"},
		{"fhbb"},
		{"eegc"},
		{"aagc"},
	},
	{
		{"ddjgg"},
		{"aaj.c"},
		{".fbbc"},
		{"hfi.."},
		{"h.iee"},
	},
	{
		{"ii..ak"},
		{"b...ak"},
		{"b.hh.c"},
		{".jjddc"},
		{"..glee"},
		{"ffgl.."},
	},
	{
		{"j...fnn"},
		{"j.kkf.."},
		{".c..bbd"},
		{".c.mm.d"},
		{"iie..a."},
		{"..e..ag"},
		{"llhh..g"},
	}
};

int n;
char ret[maxn][maxn];

int main() {
	scanf("%d", &n);
	if (n < 3) printf("-1");
	else if (n == 3) {
		F0R(i,n)
			printf("%s\n", ans[0][i]);
	}
	else {
		F0R(i,n)
			F0R(j,n)
				ret[i][j] = '.';
		int _ = 0;
		for (; _+8 <= n; _+=4) {
			FOR(i,_,_+4)
				FOR(j,_,_+4)
					ret[i][j] = ans[1][i-_][j-_];
		}
		FOR(i,_,n)
			FOR(j,_,n)
				ret[i][j] = ans[(n-_-4)+1][i-_][j-_];
		F0R(i,n)
			printf("%s\n", ret[i]);
	}
}
