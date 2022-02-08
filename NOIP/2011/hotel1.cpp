#include <cstdio>
#include <cstring>
const int COL=51;
int main()
{
	int cur[COL],last[COL],sum=0,n,k,p,colour,price;
	memset(cur,0,sizeof(cur));
	memset(last,0,sizeof(last));
	scanf("%d%d%d",&n,&k,&p);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&colour,&price);
		//printf("<%d>",i);
		cur[colour]++;
		if(price<=p){
			//printf("Copied!");
			memcpy(last,cur,sizeof(last));
		}
		sum+=last[colour];
		if(price<=p)sum--;
		//printf(" [%d] \n",last[colour]);
	}
	printf("%d\n",sum);

}