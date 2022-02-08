#include<iostream>
using namespace std;
int N,C[3<<17],D[3<<17],F[3<<17];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		int A;cin>>A;C[A]++;
	}
	for(int i=0;i++<N;)D[C[i]]++;
	long L=0,R=0;
	for(int i=1;i<=N;i++)R+=D[i];
	for(long X=1;X<=N;X++)
	{
		R-=D[X];
		L+=X*D[X];
		F[X]=(L+R*X)/X;
	}
	int id=N;
	for(int K=1;K<=N;K++)
	{
		while(id>0&&F[id]<K)id--;
		cout<<id<<endl;
	}
}

