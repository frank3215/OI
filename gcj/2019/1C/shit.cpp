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

ll n, m;
vector<string> s;

ll memo[16][16][16][16];

ll dfs(ll t, ll l, ll b, ll r){
  if(memo[t][l][b][r] != -1){
    return memo[t][l][b][r];
  }
  vector<bool> nex(256, false);
  FOR(i, t, b){
    FOR(j, l, r){
      if(s[i][j] == '.'){
        // v
        bool f = false;
        FOR(k, t, b){
          if(s[k][j] == '#'){
            f = true;
          }
        }
        if(!f){
          ll res = dfs(t, l, b, j) ^ dfs(t, j+1, b, r);
          nex[res] = true;
        }
        // h
        f = false;
        FOR(k, l, r){
          if(s[i][k] == '#'){
            f = true;
          }
        }
        if(!f){
          ll res = dfs(t, l, i, r) ^ dfs(i+1, l, b, r);
          nex[res] = true;
        }
      }
    }
  }
  REP(i, 256){
    if(!nex[i]){
      return memo[t][l][b][r] = i;
    }
  }
}

ll solve(){
  n = in();
  m = in();
  s.assign(n, "");
  REP(i, n){
    s[i] = stin();
  }
  REP(i, 16){
    REP(j, 16){
      REP(k, 16){
        REP(l, 16){
          memo[i][j][k][l] = -1;
        }
      }
    }
  }
  ll ans = 0;
  ll t = 0, b = n;
  ll l = 0, r = m;
  FOR(i, t, b){
    FOR(j, l, r){
      if(s[i][j] == '.'){
        // v
        bool f = false;
        FOR(k, t, b){
          if(s[k][j] == '#'){
            f = true;
          }
        }
        if(!f){
          ll res = dfs(t, l, b, j) ^ dfs(t, j+1, b, r);
          if(res == 0){
            ans++;
          }
        }
        // h
        f = false;
        FOR(k, l, r){
          if(s[i][k] == '#'){
            f = true;
          }
        }
        if(!f){
          ll res = dfs(t, l, i, r) ^ dfs(i+1, l, b, r);
          if(res == 0){
            ans++;
          }
        }
      }
    }
  }
  return ans;
}

int main(){

  ll t = in();
  FOR(i, 1, t+1){
    ll ans = solve();
    printf("Case #%lld: %lld\n", i, ans);
  }
  
  return 0;
}
