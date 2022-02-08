


 #include <stdio.h>
 #include <bits/stdc++.h>






using namespace std;





template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}







using li = long long int;
using lu = long long unsigned;

using ld = long double;

using pii = tuple<li, li>;
using piii = tuple<li, li, li>;
using piiii = tuple<li, li, li, li>;
using vi = vector<li>;
using vii = vector<pii>;
using viii = vector<piii>;
using vvi = vector<vi>;
using vvii = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

struct empty_t {};



int ilog2(int x){ return 31 - __builtin_clz(x); }

template <class T>
struct identity : std::unary_function <T, T> {
  T operator() (const T& x) const {return x;}
};

template<class T>
T& smin(T& x, T const& y) { x = min(x,y); return x; }

template <class T>
T& smax(T& x, T const& y) { x = max(x, y); return x; }


template<typename T>
T isqrt(T const&x){
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(sqrtl(x));
  while(ret>0 && ret*ret>x) --ret;
  while(x-ret*ret>2*ret) ++ret;
  return ret;
}

template<typename T>
T icbrt(T const&x) {
  static_assert(is_integral<T>::value, "is_integral<T>::value");
  assert(x>=T(0));
  T ret = static_cast<T>(cbrt(x));
  while(ret>0 && ret*ret*ret>x) --ret;
  while(x-ret*ret*ret>3*ret*(ret+1)) ++ret;
  return ret;
}

const char* AA = "RPS";

int dec(char c) {
  if(c=='R') return 0;
  if(c=='P') return 1;
  if(c=='S') return 2;
}

void solve(){
  int n; cin>>n;
  vector<string> S(n);
  for(li i = 0; i < (li)(n); ++i) cin>>S[i];
  vector<bitset<3>> B(500);
  for(li i = 0; i < (li)(n); ++i) for(li j = 0; j < (li)(500); ++j) {
    B[j][dec(S[i][j%S[i].size()])] = 1;
  }
  vi I(n); iota(begin(I), end(I),0);
  vi O;
  bool ok = 0;

  for(li i = 0; i < (li)(500*500); ++i) {
    li l = 1;
    for(int j : I) {
      l = l/__gcd<li>(l,S[j].size())*S[j].size();
      if(l>=i) break;
    };
    if(i>=l+10) break;

    bitset<3> b;
    for(int j : I) b[dec(S[j][i%S[j].size()])] = 1;
    if(b.count() == 3) {
      cout << "IMPOSSIBLE" << endl;
      return;
    } else if(b.count() == 1) {
      for(li j = 0; j < (li)(3); ++j) if(b[j]) O.emplace_back((j+1)%3);
      ok = 1;
      break;
    } else {
      for(li j = 0; j < (li)(3); ++j) if(b[j]&&b[(j+1)%3]) {
        O.emplace_back((j+1)%3);
        vi J;
        for(int k : I) if(dec(S[k][i%S[k].size()]) != j) J.emplace_back(k);
        I = J;
      }
    }
  }

  if(!ok) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  for(li p = (1); p <= (li)(min(500,(int)O.size())); ++p) {
    bool isp = 1;
    for(li i = 0; i < (li)((int)O.size() - p); ++i) if(O[i] != O[i+p]) isp = 0;
    if(isp) {
      for(li j = 0; j < (li)(p); ++j) cout << AA[O[j]];
      cout << endl;
      return;
    }
  }
  cout << "IMPOSSIBLE" << endl;
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n; cin>>n;
  for(li i = 0; i < (li)(n); ++i) {
    cout << "Case #" << (i+1) << ": ";
    solve();
  }
  return 0;
}
