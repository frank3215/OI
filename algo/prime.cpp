#include <stdio.h>
#include <string.h>
#define MAXN 10000000
#define MAXL 100000100
int prime[MAXN+10];
bool check[MAXL+1000];

int main(void)
{
	int n=MAXL, count=0;
	memset(check, 0, sizeof(check));
	for (int i = 2; i <= n; i++)
	{
		if (!check[i])
			prime[count++] = i;
		for (int j = 0; j < count; j++)
		{
			if (i*prime[j] > MAXL)
				break; // 过大的时候跳出
			check[i*prime[j]] = 1;
			if ((i%prime[j]) == 0) // 如果i是一个合数，而且i % prime[j] == 0
				break; 
		}
	}
	for (int i = 0; i < count; i++)
		printf("%d\n", prime[i]);
	return 0;
}
