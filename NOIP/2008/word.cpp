#include <cstdio>
bool isprime(int p){
	if(p<2)
		return 0;
	else if(p<4)
		return 1;
	else if(1-p%2)
		return 0;
	else{
		for(int i=2;i*i<=p;i++)
			if(p%i==0)
				return 0;
		return 1;
	}
}
int main(){
	return 0;
}