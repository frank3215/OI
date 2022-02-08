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
const int nax=1007;

void nope()
{
	printf("IMPOSSIBLE\n");
}

void umiem()
{
	printf("POSSIBLE\n");
}

int r, c;
int n;
vi graf[nax];

int daj(int a, int b)
{
	a--;
	b--;
	return a*c+b+1;
}

pii odw(int v)
{
	v--;
	return {(v/c)+1, (v%c)+1};
}

int los(int a, int b)
{
	return a+rand()%(b-a+1);
}

int lim;

int bylo[nax];
vi stos;

int rek(int v)
{
	lim--;
	if (lim<0)
		return 0;
	bylo[v]=1;
	stos.push_back(v);
	if ((int)stos.size()==n)
	{
		umiem();
		for (int i : stos)
		{
			pii x=odw(i);
			printf("%d %d\n", x.first, x.second);
		}
		return 1;
	}
	for (int i : graf[v])
	{
		if (bylo[i])
			continue;
		if (rek(i))
			return 1;
	}
	
	bylo[v]=0;
	stos.pop_back();
	return 0;
}

set <pii> nie;

void test()
{
	scanf("%d%d", &r, &c);
	if (nie.count({r, c}))
	{
		nope();
		return;
	}
	n=r*c;
	for (int i=1; i<=n; i++)
		graf[i].clear();
	for (int i=1; i<=r; i++)
	{
		for (int j=1; j<=c; j++)
		{
			for (int a=1; a<=r; a++)
			{
				for (int b=1; b<=c; b++)
				{
					if (i==a)
						continue;
					if (j==b)
						continue;
					if (i+j==a+b)
						continue;
					if (i-j==a-b)
						continue;
					graf[daj(i, j)].push_back(daj(a, b));
				}
			}
		}
	}
	while(1)
	{
		lim=1e5;
		for (int i=1; i<=n; i++)
		{
			bylo[i]=0;
			shandom_ruffle(graf[i].begin(), graf[i].end());
		}
		stos.clear();
		if (rek(los(1, n)))
			break;
	}
}

int main()
{
	nie.insert({2, 2});
	nie.insert({2, 3});
	nie.insert({2, 4});
	nie.insert({3, 2});
	nie.insert({3, 3});
	nie.insert({4, 2});
	int t;
	scanf("%d", &t);
	for (int i=1; i<=t; i++)
	{
		printf("Case #%d: ", i);
		test();
	}
	return 0;
}
