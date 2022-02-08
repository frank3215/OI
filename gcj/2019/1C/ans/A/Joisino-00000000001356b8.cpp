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

string solve(){
  ll n = in();
  vector<string> ss(n);
  REP(i, n){
    ss[i] = stin();
  }
  string ans = "";
  vector<bool> live(n, true);
  REP(q, INF){
    ll r = 0;
    ll s = 0;
    ll p = 0;
    REP(i, n){
      if(live[i]){
        char c = ss[i][q%SZ(ss[i])];
        if(c == 'R'){
          r = 1;
        } else if(c == 'S'){
          s = 1;
        } else if(c == 'P'){
          p = 1;
        }
      }
    }
    if(r + s + p == 0){
      break;
    }
    if(r + s + p == 3){
      return "IMPOSSIBLE";
    }
    if(r + s + p == 1){
      if(r == 1){
        ans += 'P';
      } else if(s == 1){
        ans += 'R';
      } else if(p == 1){
        ans += 'S';
      }
      return ans;
    }
    if(r + s + p == 2){
      if(r == 0){
        // s p
        ans += 'S';
        REP(i, n){
          char c = ss[i][q%SZ(ss[i])];
          if(c == 'P'){
            live[i] = false;
          }
        }
      } else if(s == 0){
        // r p
        ans += 'P';
        REP(i, n){
          char c = ss[i][q%SZ(ss[i])];
          if(c == 'R'){
            live[i] = false;
          }
        }
      } else if(p == 0){
        // r s
        ans += 'R';
        REP(i, n){
          char c = ss[i][q%SZ(ss[i])];
          if(c == 'S'){
            live[i] = false;
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
    string ans = solve();
    printf("Case #%lld: %s\n", i, ans.c_str());
  }
  
  return 0;
}
