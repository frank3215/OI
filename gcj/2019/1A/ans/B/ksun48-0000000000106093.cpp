#include <bits/stdc++.h>
using namespace std;

int n, m;
void solve(){
	vector<int> stuff = {16, 9, 7, 11, 13, 17};
	int prod = 1;
	for(int x : stuff) prod *= x;
	assert(prod >= m);
	vector<int> res;
	for(int a : stuff){
		for(int j = 0; j < 18; j++){
			cout << a << " \n"[j == 17];
		}
		cout << flush;
		int tot = 0;
		for(int j = 0; j < 18; j++){
			int r;
			cin >> r;
			tot += r;
		}
		tot %= a;
		res.push_back(tot);
	}
	int q = 0;
	while(q <= m){
		bool works = true;
		for(int i = 0; i < stuff.size(); i++){
			if((q - res[i]) % stuff[i] != 0) works = false;
		}
		if(works){
			cout << q << '\n';
			cout << flush;
			int verdict;
			cin >> verdict;
			return;
		}
		q += 1;
	}
	cout << -1 << '\n';
	cout << flush;
	int verdict;
	cin >> verdict;
}

int main(){
	int T;
	cin >> T;
	cin >> n >> m;
	for(int t = 1; t <= T; t++){
		solve();
	}
}