// 15604 [0.303pts]
#include <bits/stdc++.h>
using namespace std;

enum Type { L, R, U, D };

const int N = 600;

int n, f, k, t[N][N];

struct op{
	int v, l, r;
}h[N<<2];
int dep[N<<2] = {-1}, ch[N<<2][2];

const int S = N*N;
int s;
int T[S]; int pos[S];

void print(int id) {
	int ty = (id-1)/n, i = (id-1)%n+1;
	printf("[%c%d]", "LRUD"[ty], i);
}

const int M = 4096;
int tr[M<<1], siz;
int cmp(int x, int y) {
	if (!x || !y) return x+y;
	return h[x].v>h[y].v?x:y;
}
void update(int x) {
	//print(x);
	x += M;
	for (int i = x>>1; i; i >>= 1) {
		tr[i] = cmp(tr[i<<1], tr[i<<1|1]);
	}
}
void insert(int x) {
	assert(x < 2*M);
	tr[M+x] = x;
	update(x);
}

int main() {
	cin >> n >> f;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> t[i][j];
		}
	}
	cin >> k;
	// Left
	for (int i = 1; i <= n; ++i) {
		h[i].l = 1;
		for (int j = 1; j <= n; ++j) {
			if (h[i].v+t[i][j] <= f) {
				h[i].v += t[i][j];
				h[i].r = j;
			}
			else break;
		}
	}
	// Right
	for (int i = 1; i <= n; ++i) {
		h[n+i].r = n;
		for (int j = n; j >= 1; --j) {
			if (h[n+i].v+t[i][j] <= f) {
				h[n+i].v += t[i][j];
				h[n+i].l = j;
			}
			else break;
		}
	}
	// Up
	for (int i = 1; i <= n; ++i) {
		h[2*n+i].l = 1;
		for (int j = 1; j <= n; ++j) {
			if (h[2*n+i].v+t[j][i] <= f) {
				h[2*n+i].v += t[j][i];
				h[2*n+i].r = j;
			}
			else break;
		}
	}
	// Down
	for (int i = 1; i <= n; ++i) {
		h[3*n+i].r = n;
		for (int j = n; j >= 1; --j) {
			if (h[3*n+i].v+t[j][i] <= f) {
				h[3*n+i].v += t[j][i];
				h[3*n+i].l = j;
			}
			else break;
		}
	}
	for (int i = 1; i <= 4*n; ++i) insert(i);
	//puts("DONE");
	while (h[tr[1]].v > 0) {
		int x = tr[1], i = (x-1)%n+1, ty = (x-1)/n;
		T[++s] = ty, pos[s] = i;
		//printf("(%d)%c%d: %d %d %d %d\n", ty, "LRUD"[ty], i, x, h[x].v, h[x].l, h[x].r);
		//printf(" %d %d %d\n", h[14].v, h[14].l, h[14].r);
		// Left or Right
		if (ty == L || ty == R) {
			for (int j = h[x].l; j <= h[x].r; ++j) if (t[i][j]) {
				// Up
				//puts("U");
				if (h[j+U*n].r >= i) {
					op &cur = h[j+U*n];
					cur.v -= t[i][j];
					while (cur.r+1 <= n && cur.v+t[cur.r+1][j] <= f) {
						cur.v += t[++cur.r][j];
					}
					update(j+U*n);
				}
				// Down
				//puts("D");
				if (h[j+D*n].l <= i) {
					op &cur = h[j+D*n];
					cur.v -= t[i][j];
					while (cur.l-1 >= 1 && cur.v+t[cur.l-1][j] <= f) {
						cur.v += t[--cur.l][j];
					}
					update(j+D*n);
				}
				t[i][j] = 0;
			}
			// Left
			//puts("L");
			{
				op &cur = h[i+L*n];
				cur.l = cur.r = cur.v = 0;
				for (int j = 1; j <= n; ++j) if (t[i][j]) {
					if (!cur.l) cur.l = j;
					if (cur.v+t[i][j] <= f) {
						cur.v += t[i][j];
						cur.r = j;
					}
					else break;
				}
				update(i+L*n);
			}
			// Right
			//puts("R");
			{
				op &cur = h[i+R*n];
				cur.l = cur.r = cur.v = 0;
				for (int j = n; j >= 1; --j) if (t[i][j]) {
					if (!cur.r) cur.r = j;
					if (cur.v+t[i][j] <= f) {
						cur.v += t[i][j];
						cur.l = j;
					}
					else break;
				}
				update(i+R*n);
			}
		}
		// Up or Down
		if (ty == U || ty == D) {
			for (int j = h[x].l; j <= h[x].r; ++j) if (t[j][i]) {
				// Left
				//puts("L");
				if (h[j+L*n].r >= i) {
					op &cur = h[j+L*n];
					cur.v -= t[j][i];
					while (cur.r+1 <= n && cur.v+t[j][cur.r+1] <= f) {
						cur.v += t[j][++cur.r];
					}
					update(j+L*n);
				}
				// Right
				//puts("R");
				if (h[j+R*n].l <= i) {
					op &cur = h[j+R*n];
					cur.v -= t[j][i];
					while (cur.l-1 >= 1 && cur.v+t[j][cur.l-1] <= f) {
						cur.v += t[j][--cur.l];
					}
					update(j+R*n);
				}
				t[j][i] = 0;
			}
			// Up
			//puts("U");
			{
				op &cur = h[i+U*n];
				cur.l = cur.r = cur.v = 0;
				for (int j = 1; j <= n; ++j) if (t[j][i]) {
					if (!cur.l) cur.l = j;
					if (cur.v+t[j][i] <= f) {
						cur.v += t[j][i];
						cur.r = j;
					}
					else break;
				}
				update(i+U*n);
			}
			// Down
			//puts("D");
			{
				op &cur = h[i+D*n];
				cur.l = cur.r = cur.v = 0;
				for (int j = n; j >= 1; --j) if (t[j][i]) {
					if (!cur.r) cur.r = j;
					//printf("[%c%d]", "LRUD"[ty], i);
					if (cur.v+t[j][i] <= f) {
						cur.v += t[j][i];
						cur.l = j;
					}
					else break;
				}
				update(i+D*n);
			}
		}
	}
	cout << s << endl;
	for (int i = 1; i <= s; ++i) {
		cout << "LRUD"[T[i]] << ' ' << pos[i] << endl;
	}
}
