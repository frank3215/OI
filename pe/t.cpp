#include <bits/stdc++.h>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,b) FOR(i,0,b)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,b) ROF(i,0,b)

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define ITER(i,x) for (auto &i: x)
#define ITE(i,x) for (auto i: x)
#define IT(i,x) for (auto i = x.begin(); i != x.end(); ++i)
#define ALL(x) x.begin(), x.end()
#define P pair
#define V vector
#define I int

//#define double long double
//#define int long long

typedef long double ld;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,pii> ppp;
typedef vector<int> vi;
typedef vector<vi> vvi;

signed main() {
	int sum = 0;
	for (int i = 0, j = 1; j <= 4e6; i += j, swap(i,j)) if (j%2 == 0) sum += j;
	cout << sum << endl;
}
