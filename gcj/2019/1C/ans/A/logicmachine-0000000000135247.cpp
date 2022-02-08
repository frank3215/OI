#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int num_cases;
	cin >> num_cases;
	for(int case_num = 1; case_num <= num_cases; ++case_num){
		int n;
		cin >> n;
		vector<string> vs(n);
		for(int i = 0; i < n; ++i){ cin >> vs[i]; }
		vector<bool> done(n);
		vector<char> solution;
		bool accept = true;
		for(int i = 0; accept && i < 500; ++i){
			int mask = 0;
			for(int j = 0; j < n; ++j){
				if(done[j]){ continue; }
				const auto& s = vs[j];
				const int c = s[i % s.size()];
				switch(c){
				case 'R': mask |= 1; break;
				case 'P': mask |= 2; break;
				case 'S': mask |= 4; break;
				}
			}
			if(mask == 7){
				accept = false;
				break;
			}else if(mask == 3 || mask == 1){
				solution.push_back('P');
				for(int j = 0; j < n; ++j){
					const auto& s = vs[j];
					if(s[i % s.size()] == 'R'){ done[j] = true; }
				}
			}else if(mask == 5 || mask == 4){
				solution.push_back('R');
				for(int j = 0; j < n; ++j){
					const auto& s = vs[j];
					if(s[i % s.size()] == 'S'){ done[j] = true; }
				}
			}else if(mask == 6 || mask == 2){
				solution.push_back('S');
				for(int j = 0; j < n; ++j){
					const auto& s = vs[j];
					if(s[i % s.size()] == 'P'){ done[j] = true; }
				}
			}else{
				break;
			}
		}
		cout << "Case #" << case_num << ": ";
		if(!accept){
			cout << "IMPOSSIBLE" << endl;
		}else{
			solution.push_back('\0');
			cout << solution.data() << endl;
		}
	}
	return 0;
}

