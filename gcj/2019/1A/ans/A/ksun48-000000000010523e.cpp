#include <bits/stdc++.h>
using namespace std;

bool ok(pair<int,int> a, pair<int,int> b){
	if(a.first == b.first) return false;
	if(a.second == b.second) return false;
	if(a.first + a.second == b.first + b.second) return false;
	if(a.first - a.second == b.first - b.second) return false;
	return true;
}

vector<pair<int,int> > get_path(int r, int c){
	mt19937 mt(48);
	for(int _ = 0; _ < 1000; _++){
		vector<pair<int,int> > e;
		for(int a = 0; a < r; a++){
			for(int b = 0; b < c; b++){
				e.emplace_back(a, b);
			}
		}
		shuffle(e.begin(), e.end(), mt);
		vector<pair<int,int> > seq;
		vector<int> used(r*c, 0);
		int z = 0;

		seq.push_back(e[0]);
		used[0] = true;
		z = (z + 1) % ((int)e.size());
		while(seq.size() < e.size()){
			if(seq.back() == e[z]) break;
			if(!used[z] && ok(seq.back(), e[z])){
				used[z] = 1;
				seq.push_back(e[z]);
			}
			z = (z + 1) % ((int)e.size());
		}
		if(seq.size() == e.size()) return seq;
	}
	return {};
}

void solve(int t){
	cout << "Case #" << t << ": ";
	int r, c;
	cin >> r >> c;
	vector<pair<int, int> > z = get_path(r, c);
	if(z.empty()){
		cout << "IMPOSSIBLE" << '\n';
		return;
	}
	cout << "POSSIBLE" << '\n';
	for(pair<int,int> x : z){
		cout << 1 + x.first << ' ' << 1 + x.second << '\n';
	}
}


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		solve(t);
	}
}