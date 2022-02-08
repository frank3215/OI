#include <bits/stdc++.h>
using namespace std;

void solve(){
	int F = 5;
	int n, b, fake_f;
	cin >> n >> b >> fake_f;
	assert(fake_f >= F);
	for(int f = 0; f < F; f++){
		string g;
		for(int i = 0; i < n; i++){
			g += (char)('0' + ((i >> f) & 1));
		}
		cout << g << '\n' << flush;
	}
	vector<int> answers(n-b);
	for(int f = 0; f < F; f++){
		string res;
		cin >> res;
		for(int i = 0; i < n-b; i++){
			answers[i] ^= (res[i] - '0') << f;
		}
	}
	vector<int> broken;
	int z = 0;
	for(int i = 0; i < n-b; i++){
		while((z & 31) != answers[i]){
			cout << z << ' ';
			z++;
		}
		z++;
	}
	while(z < n){
		cout << z << ' ';
		z++;
	}
	cout << '\n';
	cout << flush;
	int res;
	cin >> res;
}


int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		solve();
	}
}