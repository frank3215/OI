#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	int num_cases, F;
	cin >> num_cases >> F;
	for(int case_num = 1; case_num <= num_cases; ++case_num){
		const int n = 119;
		vector<int> candidates;
		for(int i = 0; i < n; ++i){ candidates.push_back(i); }
		vector<char> solution;
		for(int offset = 0; offset < 4; ++offset){
			vector<vector<int>> next_candidates(5);
			for(const auto index : candidates){
				cout << (index * 5 + offset + 1) << endl << flush;
				string name;
				cin >> name;
				next_candidates[name[0] - 'A'].push_back(index);
			}
			int min_count = n;
			for(int i = 0; i < 5; ++i){
				if(count(solution.begin(), solution.end(), 'A' + i) > 0){ continue; }
				min_count = min<int>(min_count, next_candidates[i].size());
			}
			for(int i = 0; i < 5; ++i){
				if(count(solution.begin(), solution.end(), 'A' + i) > 0){ continue; }
				if(next_candidates[i].size() == min_count){
					solution.push_back('A' + i);
					candidates = next_candidates[i];
				}
			}
		}
		for(int i = 0; i < 5; ++i){
			if(count(solution.begin(), solution.end(), 'A' + i) > 0){ continue; }
			solution.push_back('A' + i);
		}
		solution.push_back('\0');
		cout << solution.data() << endl << flush;
		string status;
		cin >> status;
	}
	return 0;
}

