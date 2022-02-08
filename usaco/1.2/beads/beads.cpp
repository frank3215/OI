/*
ID: chengef2
PROG: beads
kANG: C++                 
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int n,i,ans=0;
string b;

int count(int i,int dir)
{
	int j=i;
	char c='w';
	for (j=i; j>=0 && j<2*n; j+=dir)
		if (c=='w') c=b[j];
		else if (b[j]!=c && b[j]!='w') break;
	return j;
}

int main()
{
    ofstream fout ("beads.out");
    ifstream fin ("beads.in");

	fin >> n >> b;
	b+=b;
	for (i=0; i<2*n; i++)
		ans=max( count(i+1,1)-count(i,-1)-1 , ans );

	fout<<min(n,ans)<<endl;
    return 0;
}
