#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define trav(a,x) for (auto& a: x)

#define pb push_back
#define ub upper_bound
#define s second
 
void setIO(string name) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((name+".in").c_str(),"r",stdin);
	freopen((name+".out").c_str(),"w",stdout);
}

const int MX = 100005;

vi adj;

template<class T,int SZ> struct BIT{
	T t[SZ+1];
	void add(int p, T x) {
		for (; p; p -= p&-p) t[p] += x;
	}
	T sum(int p) {
		T x = 0;
		for (; p <= SZ; p += p&-p) x += t[p];
		return x;
	}
	T query(int l, int r) {
		return sum(l)-sum(r-1);
	}
}

int main() {
}
