#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+10;

char s[N];

int main() {
	scanf("%s", s);
	int n = strlen(s);
	for (int i = 0; i < n; ++i) {
		if (s[i] == '?') s[i] = 'D';
	}
	printf("%s", s);
}
