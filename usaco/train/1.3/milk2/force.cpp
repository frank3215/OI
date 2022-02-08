/*
ID: chengef2
PROG: milk2
LANG: C++                 
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
const int maxm = 1e6+10,maxn=5e3+10;

int n,milk[2][maxn],day[maxm]={},mn=maxm,mx=0,i,j,work=0,idle=0,mx_work=0,mx_idle=0;

int main() {
    ofstream fout ("milk2.out");
    ifstream fin ("milk2.in");

	fin>>n;
	for(i=0;i<n;i++){
		fin>>milk[0][i]>>milk[1][i];
		mn=min(mn,milk[0][i]);
		mx=max(mx,milk[1][i]);
		for(j=milk[0][i];j<milk[1][i];j++)
			day[j]=1;
		//memset(&day[milk[0][i]],1,&day[milk[1][i]]-&day[milk[0][i]]);
	}

	for(i=mn;i<mx;i++)
		if(day[i]) mx_work=max(mx_work,++work),idle=0;
		else mx_idle=max(mx_idle,++idle),work=0;
	fout<<mx_work<<' '<<mx_idle<<endl;
}
