#include <bits/stdc++.h>
using namespace std;

int main() {
	for (int i = 0; i < 20; ++i) {
		assert(!system("echo 166320 83161 | ./gen > ring.in && ./ring < ring.in > ring.out"));
		if (!system("diff ring.ans ring.out > diff.log")) {
			puts("AC");
		} else {
			puts("WA!");
			break;
		}
	}
}
