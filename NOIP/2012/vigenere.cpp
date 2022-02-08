#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
int main(){
	freopen("data1/vigenere/vigenere1.in","r",stdin);
	freopen("data1/vigenere/vigenere1.out","w",stdout);
	char k[100],M[1000];
	scanf("%s",k);
	scanf("%s",M);
	int lk=strlen(k),lM=strlen(M),key[100];
	for(int i=0;i<lk;i++){
		if(islower(k[i])) key[i]=k[i]-'a';
		if(isupper(k[i])) key[i]=k[i]-'A';
	}
	for(int i=0;i<lM;i++){
		if(isupper(M[i])){
			M[i]='A'+(M[i]-'A'-key[i%lk]+26)%26;
		}
		if(islower(M[i])){
			M[i]='a'+(M[i]-'a'-key[i%lk]+26)%26;
		}
	}
	printf("%s\n",M);
	return 0;
}