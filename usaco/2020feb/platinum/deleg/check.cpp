#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 0; i < 20; ++i) {
		system("./gen > deleg.in");
		system("./std < deleg.in > deleg.ans");
		system("./deleg < deleg.in > deleg.out");
		if (system("diff deleg.ans deleg.out > diff.log")) {
			puts("WA");
			break;
		}
		puts("AC");
	}
}
