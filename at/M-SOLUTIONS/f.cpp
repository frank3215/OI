#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;

bitset<maxn> l[maxn], r[maxn], a[maxn];
int n;
char s[maxn];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", s+1);
		a[i][i] = l[i][i] = r[i][i] = 1;
		for (int j = 1; j < i ++j) {
			a[i][j] = s[j]-'0';
			a[j][i] = !a[i][j];
		}
	}
	for (int len = 1; len <= n; ++i) {
		for (int i = 1; i <= n-len+1; ++i) {
			int j = i+len-1;
			l[j][i] = (a[i]&l[j]&r[i+1]).count();
			r[i][j] = (a[	
}
