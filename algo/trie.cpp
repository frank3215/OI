#include <cstdio>
struct trie{
	static const int maxn=1000000,alpha=30;
	int t[maxn][alpha],z[maxn],tot;
	int map(char c){
		return c-'a';
	}
	void clear(){
		for(int i;tot--;){
			for(i=0;i<alpha;i++)
				t[n][i]=0;
			z[n]=0;
		}
	}
	template<typename T>
	void insert(const T &begin,const T &end,int cur=0){
		for(T i=begin;i!=end;cur=t[cur][map(*i)],i++)
			if(!t[cur][map(*i)])
				t[cur][map(*i)]=++tot;
		z[cur]++;
	}
	template<typename T>
	int find(const T &begin,const T &end,int cur=0){
		for(T i=begin;i!=end&&(i==begin||cur);cur=t[cur][map(*i)],i++);
		return cur;
	}
};
