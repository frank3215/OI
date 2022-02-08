/*
ID: chengef2
TASK: namenum
PROG: namenum
LANG: C++                 
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string n,dict[5001];
int tot=0,i,j,nok=1;

bool npair(int i,char c){
	if(i<5) return (c-'A')/3!=i;
	else if(i==5) return (c!='S'&&c!='P'&&c!='R');
	else return (c-'B')/3!=i;
}

int main() {
    ofstream fout ("namenum.out");
    ifstream fin ("namenum.in");
	ifstream fdict ("dict.txt");

	fin>>n;
	while (fdict >> dict[tot++]);
	for (int i=0;i<tot;i++)
		if (dict[i].size()==n.size())
			for (int j=0; j<=n.size(); j++){
				if (j==n.size()) fout<<dict[i]<<endl,nok=0;
				else if(npair(n[j]-'2',dict[i][j])) break;
			}
	if(nok) fout<<"NONE"<<endl;
    return 0;
}
