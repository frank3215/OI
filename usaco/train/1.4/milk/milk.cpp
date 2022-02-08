/*
ID: chengef2
TASK: milk
PROG: milk.cpp
LANG: C++                 
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#define IO(s) ofstream fout ( s ".out");ifstream fin ( s ".in");
using namespace std;

int main() {
	int n,m,i,ans=0;
	IO("milk");
	pair<int,int> p[5000];

	fin >> m >> n;
	for(i=0;i<n;i++)
		fin >> p[i].first >> p[i].second;
	sort(p,p+n);
	for(i=0;m>0;m-=p[i++].second)
		ans+=p[i].first*min(p[i].second,m);
	fout << ans << endl;
}
