#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int inf=2147483647;
int n,m,d[100010],now;
struct node
{
	int x,d,v;
	bool operator < (const node &y) const
	{
		int a=x+now*d;
		int b=y.x+now*y.d;
		if (a==b)
		{
			return d<y.d;
		}
		else
		{
			return a<b;
		}
	}
};
struct col
{
	node x,y;
	int ti;
	col(node a,node b)
	{
		x=a;
		y=b;
		ti=(y.x-x.x)/2;
	}
	bool operator < (const col &a) const
	{
		if (ti!=a.ti)
		{
			return ti<a.ti;
		}
		if (x.x!=a.x.x)
		{
			return x.x<a.x.x;
		}
		if (x.v!=a.x.v)
		{
			return x.v<a.x.v;
		}
		if (y.x!=a.y.x)
		{
			return y.x<a.y.x;
		}
		return y.v<a.y.v;
	}
};
struct yxg
{
	set<node> sn;
	set<col> sc;
	void insc(node x,node y)
	{
		if (x.d>0 && y.d<0)
		{
			sc.insert(col(x,y));
		}
	}
	void delc(node x,node y)
	{
		if (x.d>0 && y.d<0)
		{
			sc.erase(col(x,y));
		}
	}
	void del(node x)
	{
		set<node>::iterator it,nxt,pre;
		it=sn.insert(x).first;
		nxt=it;
		nxt++;
		pre=it;
		pre--;
		if (nxt!=sn.end())
		{
			delc(*it,*nxt);
		}
		if (it!=sn.begin())
		{
			delc(*pre,*it);
			if (nxt!=sn.end())
			{
				insc(*pre,*nxt);
			}
		}
		sn.erase(it);
	}
	void ins(node x)
	{
		if (!x.v)
		{
			return;
		}
		if (sn.find(x)!=sn.end())
		{
			x.v+=sn.find(x)->v;
			del(*sn.find(x));
		}
		set<node>::iterator it,nxt,pre;
		it=sn.insert(x).first;
		nxt=it;
		nxt++;
		pre=it;
		pre--;
		if (it!=sn.begin())
		{
			if (nxt!=sn.end())
			{
				delc(*pre,*nxt);
			}
			insc(*pre,*it);
		}
		if (nxt!=sn.end())
		{
			insc(*it,*nxt);
		}
	}
	int reset(int x,int y)
	{
		node l,r;
		l=(node){x+1+now,-1,y};
		r=(node){x-1-now,1,y};
		int a,b;
		if (sn.find(l)!=sn.end())
		{
			a=sn.find(l)->v;
		}
		else
		{
			a=0;
		}
		if (sn.find(r)!=sn.end())
		{
			b=sn.find(r)->v;
		}
		else
		{
			b=0;
		}
		return max(0,y-max(a,b));
	}
	node cancel(node x,node y)
	{
		if (x.v>y.v)
		{
			return (node){x.x,x.d,x.v-y.v};
		}
		else
		{
			return (node){y.x,y.d,y.v-x.v};
		}
    }
    void Col(col x)
    {
    	del(x.x);
    	del(x.y);
    	ins(cancel(x.x,x.y));
	}
	void maintain(int x)
	{
		while (!sc.empty() && sc.begin()->ti<=x)
		{
			Col(*sc.begin());
		}
	}
	int ask()
	{
		int res=0;
		for (set<node>::iterator it=sn.begin();it!=sn.end();it++)
		{
			if ((*it).d>0)
			{
				res+=(*it).v;
			}
		}
		return res;
	}
}a[100010];
void merge(yxg &a,yxg &b)
{
	if (a.sn.size()<b.sn.size())
	{
		swap(a.sn,b.sn);
		swap(a.sc,b.sc);
	}
	for (set<node>::iterator it=b.sn.begin();it!=b.sn.end();it++)
	{
		a.ins(*it);
	}
}
vector<pair<int,int> > v[100010],fish[100010];
void dfs(int x,int fa)
{
	for (int i=0;i<v[x].size();i++)
	{
		int y=v[x][i].x;
		if (y==fa)
		{
			continue;
		}
		d[y]=d[x]+v[x][i].y;
		dfs(y,x);
	}
}
void solve(int x,int fa)
{
	for (int i=0;i<v[x].size();i++)
	{
		int y=v[x][i].x;
		if (y==fa)
		{
			continue;
		}
		solve(y,x);
		now=-d[y];
		a[y].maintain(-(d[x]+1));
		now=-(d[x]+1);
		merge(a[x],a[y]);
	}
	now=-(d[x]+1);
	for (int i=0;i<fish[x].size();i++)
	{
		fish[x][i].y=a[x].reset(fish[x][i].x,fish[x][i].y);
	}
	a[x].maintain(-d[x]);
	now=-d[x];
	for (int i=0;i<fish[x].size();i++)
	{
		a[x].ins((node){fish[x][i].x+now,-1,fish[x][i].y});
		a[x].ins((node){fish[x][i].x-now,1,fish[x][i].y});
	}
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		w*=2;
		v[x].push_back(make_pair(y,w));
		v[y].push_back(make_pair(x,w));
	}
	scanf("%d",&m);
	for (int i=0;i<m;i++)
	{
		int d,f,p;
		scanf("%d%d%d",&d,&f,&p);
		d*=2;
		fish[p].push_back(make_pair(d,f));
	}
	dfs(1,0);
	solve(1,0);
	a[1].maintain(inf);
	printf("%d\n",a[1].ask());
	return 0;
}
