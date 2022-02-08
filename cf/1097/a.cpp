#include <cstdio>
#include <iostream>
int main() {
	char s[3];
	scanf("%s", s);
	char t[3];
	for (int i = 0; i < 5; ++i) {
		scanf("%s", t);
		if (s[0] == t[0] || s[1] == t[1]) {
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return  -0;
}
