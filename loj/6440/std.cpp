//by yjz
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 998244353;
ll qpow(ll x, ll k) {return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int mat_sz;
template<const int mat_mxsz>
struct matrix
{
	int a[mat_mxsz][mat_mxsz];
	matrix(int x=0)
	{
		for (int i=0; i<mat_mxsz; i++) for (int j=0; j<mat_mxsz; j++) a[i][j] = i==j ? x : 0;
	}
	matrix operator + (const matrix &t) const
	{
		matrix ret;
		for (int i=0; i<mat_sz; i++) for (int j=0; j<mat_sz; j++) ret.a[i][j]=(a[i][j]+t.a[i][j])%mod;
		return ret;
	}
	matrix operator - (const matrix &t) const
	{
		matrix ret;
		for (int i=0; i<mat_sz; i++) for (int j=0; j<mat_sz; j++) ret.a[i][j]=(a[i][j]-t.a[i][j])%mod;
		return ret;
	}
	matrix operator * (const matrix &t) const
	{
		matrix ret(0);
		unsigned long long tmp[20][20] = {};
		for (int i=0; i<mat_sz; i++)
		{
			for (int j=0; j<mat_sz; j++)
			{
				if (!a[i][j]) continue;
				for (int k=0; k<mat_sz; k++)
				{
					tmp[i][k] += 1ll*a[i][j]*t.a[j][k];
					if (j==10) tmp[i][k] %= mod;
				}
			}
			for (int k=0; k<mat_sz; k++) ret.a[i][k] = tmp[i][k]%mod;
		}
		return ret;
	}
	void out(int n = mat_sz)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				cout<<a[i][j]<<" ";
			}
			cout<<endl;
		}
	}
};
typedef matrix<20> MAT;
MAT qpow(MAT x, ll k) {return k==0?MAT(1):(k&1?qpow(x*x, k>>1)*x:qpow(x*x, k>>1));}
//op: U R  U<R
//A^cntr B^cntu
struct node
{
	ll U, R;
	MAT curB, curA, sum;
	node() : U(0), R(0), curB(1), curA(1), sum(0) {}
	node operator + (const node &t) const
	{
		node ret;
		ret.U = U+t.U;
		ret.R = R+t.R;
		ret.curB = curB*t.curB;
		ret.curA = curA*t.curA;
		ret.sum = sum+curA*t.sum*curB;
		return ret;
	}
}NU, NR;
node qsum(node x, ll k) {return k==0? node(): (k&1? qsum(x+x, k>>1)+x: qsum(x+x, k>>1));}
ll divdown(ll P1, ll P2, ll R, ll Q)
{
	ll ret = ((long double)1.0*P1*P2+R)/Q;
	while (P1*P2+R-Q*(ret+1)>=0) ret++;
	while (P1*P2+R-Q*ret<0) ret--;
	return ret;
}
node solve(ll P, ll Q, ll R, ll L, node A, node B)
{
	assert(P>=0); assert(Q>0); assert(R>=0); assert(L>=0);
	R %= Q;
	if (L==0) return node();
	if (P>=Q) return solve(P%Q, Q, R, L, A, qsum(A, P/Q)+B);
	ll M = divdown(L, P, R, Q);
	if (M==0) return qsum(B, L);
	ll cnt = L-divdown(Q, M, -R+P-1, P)+1;
	return qsum(B, (Q-R-1)/P)+A+solve(Q, P, -R-1+Q, M-1, B, A)+qsum(B, cnt);
}
int main()
{
	MAT A, B;
	ll P, Q, L, R, N;
	cin>>P>>Q>>R>>L>>N;
	mat_sz = N;
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>A.a[i][j];
	for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>B.a[i][j];
	NU.U = 1; NU.curB = B;
	NR.R = 1; NR.curA = A; NR.sum = A;
	node cur = qsum(NU, R/Q)+solve(P, Q, R, L, NU, NR);
	MAT ans = cur.sum;
	ans.out(N);
	return 0;
}
