/*   我们知道： a%b = a - (a/b)*b（这里的 “/” 指的是整除，例如 5/2=2 , 1/3=0），那么，我们可以进一步得到：
	gcd = b*x1 + (a-(a/b)*b)*y1
	 	= b*x1 + a*y1 – (a/b)*b*y1
	 	= a*y1 + b*(x1 – a/b*y1)
*/
// calc solution for ax+by=gcd(a,b) and returns gcd(a,b)
int exgcd(int &x,int &y,int a,int b){
	if(b==0){
		y=0,x=1;
		return a;
	}
	int d=exgcd(y,x,b,a%b);
	y-=(a/b)*x;
	return d;
}
