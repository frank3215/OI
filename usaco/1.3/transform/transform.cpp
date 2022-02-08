/*
ID: chengef2
PROG: transform
LANG: C++                 
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

int n,i,j,k,ans=7;
char a[10][11]={},b[10][11]={},c[10][11];

bool cmp()
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(a[i][j]!=b[i][j]) return 1;
	return 0;
}
void rot90()
{
	for (int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i][j]=a[n-j-1][i];
	memcpy(a,c,sizeof(a));
}
void reflx()
{
	for (int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			c[i][n-j-1]=a[i][j];
	memcpy(a,c,sizeof(a));
}
int main()
{
    ofstream fout ("transform.out");
    ifstream fin ("transform.in");
	fin >> n;
	for ( i=0; i<n; i++)
		fin >> a[i];
	for ( i=0; i<n; i++)
		fin >> b[i];
	for ( j=1,rot90(); j<4&&cmp(); j++) rot90();
	if (j<4) ans = (j?j:6);
	else{
		reflx();
		for ( j=0; j<4&&cmp(); j++) rot90();
		if(j<4) ans = (j?5:4);
		else if(!cmp()) ans = 6;
	}
	fout << ans << endl;
    return 0;
}
