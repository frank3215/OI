#include <bits/stdc++.h>
      
#define FOR(i,a,b) for(ll i = (a); i < (ll)(b); i++)
#define REP(i,n) FOR(i,0,n)
#define YYS(x,arr) for(auto& x:arr)
#define PW(x) (1LL<<(x))
#define SZ(x) ((ll)(x).size())

#define pb emplace_back
#define fi first
#define se second

using namespace std;

using ld = long double;
using ll = long long int;

const ll INF = (ll)1e9 + 10;
const ll INFLL = (ll)1e18 + 10;
const ll MOD = 1e9+7;
     
template<class T> T &chmin( T &a , const T &b ){ return a = min(a,b); }
template<class T> T &chmax( T &a , const T &b ){ return a = max(a,b); }
template<class T> void UNIQUE(vector<T> &a){ a.erase(unique(a.begin(), a.end()), a.end()); }

template<class S, class T> ostream& operator << (ostream& os, const pair<S, T> v){
  os << "(" << v.first << ", " << v.second << ")"; return os;
}
template<class T> ostream& operator << (ostream& os, const vector<T> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << " ";} os << v[i];} return os;
}
template<class T> ostream& operator << (ostream& os, const vector<vector<T>> v){
  for(int i = 0; i < v.size(); i++){if(i > 0){os << endl;} os << v[i];} return os;
}

ll in(){long long int x; assert(scanf("%lld", &x) == 1); return x;}
ld fin(){double x; assert(scanf("%lf", &x) == 1); return x;}
char yuyushiki[1000010]; string stin(){assert(scanf("%s", yuyushiki) == 1); return yuyushiki;}

// head

ll t, f;

ll ask(ll a, ll b){
  ll p = a * 5 + b + 1;
  printf("%lld\n", p);
  fflush(stdout);
  string s = stin();
  return s[0] - 'A';
}

void solve(){
  vector<vector<ll>> a(119, vector<ll>(5, -1));
  vector<bool> live(119, true);
  vector<bool> used(5, false);
  vector<ll> ans(5, -1);
  ll al = 120;
  REP(p, 5){
    vector<ll> cnt(5, 0);
    REP(i, 119){
      if(live[i]){
        ll res = ask(i, p);
        a[i][p] = res;
        cnt[res]++;
      }
    }
    // cerr << cnt << " : " << al / (5 - p) - 1 << endl;
    REP(i, 5){
      if(!used[i] && cnt[i] == al / (5 - p) - 1){
        ans[p] = i;
        used[i] = true;
      }
    }
    REP(i, 119){
      if(a[i][p] != ans[p]){
        live[i] = false;
      }
    }
    al /= 5 - p;
  }
  // cerr << ans << endl;
  REP(i, 5){
    printf("%c", (char)(ans[i] + 'A'));
  }
  printf("\n");
  fflush(stdout);
  string s = stin();
  if(s[0] == 'N'){
    exit(0);
  }
}

int main(){

  t = in();
  f = in();

  REP(i, t){
    solve();
  }
  
  
  return 0;
}
