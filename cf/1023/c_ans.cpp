#include<string>
#include<iostream>
using namespace std;
int main()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	for(int i=1;i<n;i++)
	{
		if(n==k)
		{
			cout<<s;
			break;
		}
		if(s[i] == ')')
		{
			s.erase(i-1,2);
			n-=2;
			i-=2;
		}
	}
}
