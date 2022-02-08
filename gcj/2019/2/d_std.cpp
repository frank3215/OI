#include <bits/stdc++.h>
using namespace std;

using ll = long long;
ll modinv(ll a, ll m) {
	assert(m > 0);
	if (m == 1) return 0;
	a %= m;
	if (a < 0) a += m;
	assert(a != 0);
	if (a == 1) return 1;
	return m - modinv(m, a) * m / a;
}

template <int MOD_> struct modnum {
	private:
	int v;
	public:
	static const int MOD = MOD_;

	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int () const { return v; }
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

	modnum operator ~ () const {
		modnum res;
		res.v = modinv(v, MOD);
		return res;
	}

	modnum& operator += (const modnum& o) {
		v += o.v;
		if (v >= MOD) v -= MOD;
		return *this;
	}
	modnum& operator -= (const modnum& o) {
		v -= o.v;
		if (v < 0) v += MOD;
		return *this;
	}
	modnum& operator *= (const modnum& o) {
		v = int(ll(v) * ll(o.v) % MOD);
		return *this;
	}
	modnum& operator /= (const modnum& o) {
		return *this *= (~o);
	}

	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

using num = modnum<int(1e9)+7>;



void solve(int t){
	vector<vector<int> > edges, redges;

	cout << "Case #" << t << ": ";
	int m;
	cin >> m;
	edges.assign(m, vector<int>(2));
	redges.assign(m, {});
	for(int i = 0; i < m; i++){
		cin >> edges[i][0] >> edges[i][1];
		edges[i][0]--; edges[i][1]--;
		redges[edges[i][0]].push_back(i);
		redges[edges[i][1]].push_back(i);
	}
	vector<ll> treasury(m);
	for(int i = 0; i < m; i++) cin >> treasury[i];
	vector<int> vis1(m, 0);
	vector<int> vis2(m, 0);
	{
		vector<int> bfs;
		int s = 0;
		for(int i = 0; i < m; i++){
			if(treasury[i] > 0){
				bfs.push_back(i);
				vis1[i] = 1;
			}
		}
		while(s < bfs.size()){
			int v = bfs[s];
			s += 1;
			for(int w : edges[v]){
				if(!vis1[w]){
					vis1[w] = 1;
					bfs.push_back(w);
				}
			}
		}
	}
	{
		vector<int> bfs;
		int s = 0;
		bfs.push_back(0); vis2[0] = 1;
		while(s < bfs.size()){
			int v = bfs[s];
			s += 1;
			for(int w : redges[v]){
				if(!vis2[w]){
					vis2[w] = 1;
					bfs.push_back(w);
				}
			}
		}
	}
	if(!vis1[0]){
		cout << 0 << '\n';
		return;
	}
	vector<int> ok(m);
	for(int i = 0; i < m; i++) ok[i] = vis1[i] && vis2[i];
	vector<vector<int> > new_edges(m);
	for(int i = 0; i < m; i++){
		for(int j : edges[i]){
			if(ok[i] && ok[j]){
				new_edges[i].push_back(j);
			}
		}
	}
	vector<int> vis3(m, 0); // reachable from lead
	{
		vector<int> bfs;
		int s = 0;
		vis3[0] = 1;
		bfs.push_back(0);
		while(s < bfs.size()){
			int v = bfs[s];
			s += 1;
			for(int w : new_edges[v]){
				if(!vis3[w]){
					vis3[w] = 1;
					bfs.push_back(w);
				}
			}
		}
	}
	for(int i = 0; i < m; i++){
		if(new_edges[i].size() >= 2 && vis3[i]){
			cout << "UNBOUNDED" << '\n';
			return;
		}
	}
	new_edges[0] = {};

	// if cycle, unbounded
	// else, dp
	vector<int> in_degree(m, 0);

	vector<vector<int> > rev_edges(m);
	for(int i = 0; i < m; i++){
		for(int j : new_edges[i]){
			rev_edges[j].push_back(i);
			in_degree[i] += 1;
		}
	}
	vector<num> dp(m, 0);
	dp[0] = 1;
	{
		vector<int> to_delete;
		for(int i = 0; i < m; i++){
			if(ok[i] && in_degree[i] == 0){
				to_delete.push_back(i);
			}
		}
		assert(to_delete.size() == 1);
		int s = 0;
		while(s < to_delete.size()){
			int v = to_delete[s];
			s += 1;
			for(int w : rev_edges[v]){
				in_degree[w] -= 1;
				dp[w] += dp[v];
				if(in_degree[w] == 0){
					to_delete.push_back(w);
				}
			}
		}
	}
	for(int i = 0; i < m; i++){
		if(in_degree[i] > 0){
			cout << "UNBOUNDED" << '\n';
			return;
		}
	}
	num ans = 0;
	for(int i = 0; i < m; i++){
		if(ok[i]){
			ans += dp[i] * treasury[i];
		}
	}

	cout << (int)ans << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		solve(t);
	}
}

