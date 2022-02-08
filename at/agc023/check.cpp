#include <bits/stdc++.h>
using namespace std;

int main() {
	int cnt = 0;
	do {
		cout << "AC" << endl;
		system("./gen > in; ./std < in > ans; ./f < in > out");
	} while (++cnt <= 10 && !system("diff out ans"));
}
