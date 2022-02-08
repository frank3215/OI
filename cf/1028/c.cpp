#include <cstdio>
#include <iostream>
using namespace std;
const int maxn=133000,inf=1e9+1;
struct rect{
	int x1,x2,y1,y2;
	rect operator *(const rect &r) const{
		rect res;
		res.x1=max(x1,r.x1);
		res.y1=max(y1,r.y1);
		res.x2=min(x2,r.x2);
		res.y2=min(y2,r.y2);
		return res;
	}
	operator bool() const { return x1<=x2&&y1<=y2; }
	void scan(){
		cin >> x1 >> y1 >> x2 >> y2;
	}
}r[maxn]={{-inf,inf,-inf,inf}},pre[maxn],suf,tmp;
/*ostream& operator <<(ostream &out,rect r){
	 return out << r.x1 << r.y1 << r.x2 << r.y2;
}*/
int n,i,x1[maxn],x2[maxn],y1[maxn],y2[maxn];
int main(){
	cin>>n;
	pre[0]=suf=r[0];
	for(i=1;i<=n;i++){
		r[i].scan();
		pre[i]=pre[i-1]*r[i];
		//cout << r[i] << endl;
	}
	for(i=n;i;i--){
		if((tmp=suf*pre[i-1])){
			cout << tmp.x1 << ' ' << tmp.y1 << endl;
			break;
		}
		suf=suf*r[i];
	}
}
