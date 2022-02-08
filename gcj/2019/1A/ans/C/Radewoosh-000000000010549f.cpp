//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

#define shandom_ruffle random_shuffle

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
const int nax=200*1007;
const int alfa=26;

int n;

char wcz[nax];

int m;
int dz[nax][alfa];
vi graf[nax];
int ile[nax];

int wyn;

int dfs(int v)
{
	int ret=ile[v];
	for (int i : graf[v])
		ret+=dfs(i);
	if (v && ret>=2)
	{
		wyn+=2;
		ret-=2;
	}
	return ret;
}

void test()
{
	wyn=0;
	scanf("%d", &n);
	m=0;
	for (int i=0; i<=n*50; i++)
	{
		graf[i].clear();
		ile[i]=0;
		for (int j=0; j<alfa; j++)
			dz[i][j]=0;
	}
	for (int i=1; i<=n; i++)
	{
		scanf("%s", wcz+1);
		int d=strlen(wcz+1);
		int v=0;
		for (int j=d; j; j--)
		{
			int c=wcz[j]-'A';
			if (!dz[v][c])
			{
				m++;
				dz[v][c]=m;
				graf[v].push_back(m);
			}
			v=dz[v][c];
		}
		ile[v]++;
	}
	dfs(0);
	printf("%d\n", wyn);
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++)
	{
		printf("Case #%d: ", i);
		test();
	}
	return 0;
}
