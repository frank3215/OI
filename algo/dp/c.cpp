#include <iostream>
int a,b,c[100][100];
int main(){
    std::cin>>a>>b;
    for(int i=0;i<a;i++)
	for(int j=0;j<b;j++)
	    std::cin>>c[i][j];
    std::cout<<a+b<<endl;
    return 0;
}
