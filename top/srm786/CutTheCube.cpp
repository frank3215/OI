#include <bits/stdc++.h>
using namespace std;

class CutTheCube{
public:
	int findWinner(int L, int B, int H) {
		return (long long)L*B*H%2?2:1;
	}
};

int main() {
	int L, B, H;
	cin >> L >> B >> H;
	cout << CutTheCube().findWinner(L, B, H) << endl;
}
