/*
ID: chengef2
TASK: dualpal
PROG: dualpal
LANG: C++                 
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int b,i,j,n,s,cnt=0;

string base(int b,int n){
	string s;
	for(; n; n/=b) s += (n%b<10 ? '0' : '7') + char(n%b);
//	reverse(s.begin(),s.end());
	return s;
}

bool ispal(string a){
	for (int j=0; j<a.size(); j++)
		if (a[j] != a[a.size()-j-1]) return 0;
	return 1;
}

int main() {
    ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
	fin >> n >> s;
	for (i=s+1; n; i++){
		for(b=2,cnt=0; b<=10; b++)
			cnt += ispal( base(b,i) );
		if(cnt>=2)
			fout<<i<<endl,n--;
	}
    return 0;
}
