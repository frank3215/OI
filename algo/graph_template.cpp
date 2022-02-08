class node{
	int val;
};
class edge{
	int u,v,w;
	edge(int u,int v,int w=0):u(u),v(v),w(w) {}
};
class graph {
	public:
		int n, m, tot, ans,
			hd[maxn], nx[maxn];
		edge e[2*maxm];
		void init() {

		}
		void con(int u,int v,int w=0) {
			e[++tot] = edge(u,v,w);
			nx[tot] = hd[u];
			hd[u] = tot;
		}
		void read() {
			init();
			scanf("%d%d", &n, &m);
			for(int i=0,u,v;i<n;i++)
				scanf("%d%d",&u,&v),
				con(u,v),con(v,u);
		}	
};
