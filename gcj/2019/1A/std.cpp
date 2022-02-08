#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void solve(int t){
	cout << "Case #" << t << ": ";
	int n;
	cin >> n;
	int ans = 0;
	vector<string> words(n);
	for(int i = 0; i < n; i++){
		cin >> words[i];
	}
	map<pair<int,string>, vector<int> > locations;
	for(int i = 0; i < n; i++){
		string s = words[i];
		reverse(s.begin(), s.end());
		for(int v = 1; v <= (int)s.size(); v++){
			locations[{v, s.substr(0, v)}].push_back(i);
		}
	}
	vector<int> used(n, 0);
	while(!locations.empty()){
		auto it = prev(locations.end());
		vector<int> z = it->second;
		locations.erase(it);
		vector<int> unused;
		for(int x : z){
			if(used[x]) continue;
			unused.push_back(x);
		}
		if((int)unused.size() >= 2){
			int a = unused[0];
			int b = unused[1];
			used[a] = used[b] = 1;
			ans += 1;
		}
	}

	cout << ans * 2 << '\n';
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		solve(t);
	}
}
