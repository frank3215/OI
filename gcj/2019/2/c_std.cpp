#include <bits/stdc++.h>
using namespace std;

using ll = long long;


ll inf = 1e16;
pair<ll,ll> red(pair<ll,ll> a){
	ll g = __gcd(a.first, a.second);
	assert(g != 0);
	return {a.first / g, a.second / g};
}
vector<vector<ll> > cf(pair<ll, ll> a){
	vector<ll> cf1;
	while(1){
		if(a.first == 0) break;
		swap(a.first, a.second);
		cf1.push_back(a.first / a.second);
		a.first %= a.second;
		if(a.first == 0){
			break;
		}
	}
	vector<ll> cf2 = cf1;
	if(cf2.size() > 0) cf2.back() --;
	cf2.push_back(1);
	cf1.push_back(inf);
	cf2.push_back(inf);
	return {cf1, cf2};
}
pair<ll,ll> make_fraction(vector<ll> cf){
	pair<ll,ll> x = {0, 1};
	reverse(cf.begin(), cf.end());
	for(ll a : cf){
		if(a == inf) continue;
		x.first += a * x.second;
		swap(x.first, x.second);
	}
	return x;
}

pair<ll,ll> mid_slow(pair<ll,ll> a, pair<ll,ll> b){
	a = red(a);
	b = red(b);
	for(ll n = 1; ; n++){
		ll k = 1 + (n * a.first) / a.second;
		if(k <= 0 || k >= n) continue;
		if(k * b.second >= n * b.first) continue;
		return {k, n};
	}
}
void pr(pair<ll,ll> c){
	cout << c.first << "/" << c.second << " ";
}


pair<ll,ll> mid(pair<ll,ll> a, pair<ll,ll> b){
	a = red(a);
	b = red(b);
	vector<vector<ll> > fa = cf(a);
	vector<vector<ll> > fb = cf(b);
	pair<ll,ll> best = {a.first + b.first, a.second + b.second};
	for(vector<ll> c1 : fa){
		for(vector<ll> c2 : fb){
			assert(c1 != c2);
			vector<ll> cm;
			for(int i = 0; ; i++){
				assert(i < c1.size() && i < c2.size());
				if(c1[i] == c2[i]){
					cm.push_back(c1[i]);
				} else {
					cm.push_back(min(c1[i], c2[i]) + 1);
					break;
				}
			}
			pair<ll,ll> f = make_fraction(cm);
			if(f.first * a.second > f.second * a.first){
				if(b.first * f.second > b.second * f.first){
					if(f.first <= best.first && f.second <= best.second){
						best = f;
					}
				}
			}
			/*pr(make_fraction(c1));
			pr(make_fraction(c2));
			pr(make_fraction(cm));
			cout << endl;*/
		}
	}
	//pr(a); pr(b); pr(best);
	//cout << endl;
	return best;
}

void test(){
	cf({14155, 100000});
	cf({14165, 100000});
	pair<ll,ll> a1 = make_fraction(cf({14155, 100000})[0]);
	pair<ll,ll> b1 = make_fraction(cf({14155, 100000})[1]);
	mt19937 mt(48);
	while(1){
		ll n1 = mt() % ((ll)1e9) + 2;
		ll n2 = mt() % ((ll)1e9) + 2;
		ll a = 1 + mt() % (n1 - 1);
		ll b = 1 + mt() % (n2 - 1);
		if(n2 * a >= n1 * b) continue;
		cout << a << " " << n1 << " " << b << " " << n2 << endl;
		pr(mid({a,n1}, {b,n2}));
		cout << endl;
		//assert(mid_slow({a,n1}, {b,n2}) == mid({a,n1}, {b,n2}));
	}
}

pair<ll, ll> _min(pair<ll, ll> a, pair<ll,ll> b){
	if(a.first * b.second <= b.first * a.second) return a;
	return b;
}

pair<ll, ll> _max(pair<ll, ll> a, pair<ll,ll> b){
	if(a.first * b.second >= b.first * a.second) return a;
	return b;
}

void solve(int t){
	cout << "Case #" << t << ": ";
	ll n;
	cin >> n;
	vector<ll> a(n), b(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
	}
	vector<pair<ll, ll> > lbs;
	vector<pair<ll, ll> > ubs;
	for(int i = 0; i + 1 < n; i++){
		ll r = a[i+1] - a[i];
		ll s = b[i+1] - b[i];
		if(r <= 0 && s <= 0){
			cout << "IMPOSSIBLE" << '\n';
			return;
		}
		if(r >= 0 && s >= 0) continue;
		ll g = __gcd(abs(r), abs(s));
		r /= g; s /= g;
		if(r > 0 && s < 0){
			ubs.emplace_back(r, -s);
		} else if(r < 0 && s > 0){
			lbs.emplace_back(-r, s);
		} else assert(false);
	}
	pair<ll, ll> lb = {1, int(1e9) + 7};
	pair<ll, ll> ub = {int(1e9) + 7, 1};
	for(pair<ll, ll> x : lbs){
		lb = _max(lb, x);
	}
	for(pair<ll, ll> x : ubs){
		ub = _min(ub, x);
	}
	if(_max(lb, ub) == lb){
		cout << "IMPOSSIBLE" << '\n';
		return;
	}
	pair<ll,ll> v = mid(lb, ub);
	cout << v.second << " " << v.first << endl;
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		solve(t);
	}
}

