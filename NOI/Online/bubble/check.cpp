#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 0; i < 20; ++i) {
		assert(!system("echo 100 100 | ./gen > bubble.in && ./brute < bubble.in > bubble.ans && ./bubble < bubble.in > bubble.out"));
		if (!system("diff bubble.ans bubble.out > diff.log")) {
			puts("AC");
		} else {
			puts("WA!");
			break;
		}
	}
}
