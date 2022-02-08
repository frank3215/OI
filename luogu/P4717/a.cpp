#include <bits/stdc++.h>
using namespace std;

const int N = 17, P = 998244353, inv2 = (P+1)/2;
typedef long long ll;

int n, A[1<<N], B[1<<N];
int a[1<<N], b[1<<N];

void cpy() {
	memcpy(a, A, sizeof(a));
	memcpy(b, B, sizeof(b));
}
void get() {
	for (int i = 0; i < (1<<n); ++i) {
		a[i] = (ll)a[i]*b[i]%P;
	}
}
void print() {
	for (int i = 0; i < (1<<n); ++i) {
		printf("%d ", a[i]);
	}
	putchar('\n');
}
void XOR(int *a, bool flag=false) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1<<n); ++j) if ((j>>i&1) == 0) {
			int x = a[j], y = a[j+(1<<i)];
			if (flag) {
				x = (ll)x*inv2%P;
				y = (ll)y*inv2%P;
			}
			a[j] = (x+y)%P;
			a[j+(1<<i)] = (x-y+P)%P;
		}
	}
}
void OR(int *a, bool flag=false) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1<<n); ++j) if ((j>>i&1) == 0) {
			int x = a[j], y = a[j+(1<<i)];
			if (flag) x = P-x;
			a[j+(1<<i)] = (y+x)%P;
		}
	}
}
void AND(int *a, bool flag=false) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1<<n); ++j) if ((j>>i&1) == 0) {
			int x = a[j], y = a[j+(1<<i)];
			if (flag) y = P-y;
			a[j] = (y+x)%P;
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < (1<<n); ++i) {
		scanf("%d", A+i);
	}
	for (int i = 0; i < (1<<n); ++i) {
		scanf("%d", B+i);
	}
	cpy(), OR(a), OR(b), get(), OR(a, 1), print();
	cpy(), AND(a), AND(b), get(), AND(a, 1), print();
	cpy(), XOR(a), XOR(b), get(), XOR(a, 1), print();
}
