#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int N,K,A[50],S,T;
ll res;
map<pair<int,pair<int,int>>,ll>mp;

int main(){
	cin>>N>>K>>S>>T;
	for(int i=0;i<N;i++){
		cin>>A[i];
	}
	for(int i=0;i<N;i++){
		if((A[i]&S)==S&&(A[i]|T)==T){
			queue<pair<pair<int,pair<int,int>>,ll>>q;
			for(auto p:mp){
				if(p.first.first==K)continue;
				q.push({{p.first.first+1,{p.first.second.first&A[i],p.first.second.second|A[i]}},p.second});
			}
			while(!q.empty()){
				mp[q.front().first]+=q.front().second;
				q.pop();
			}
			mp[{1,{A[i],A[i]}}]++;
			cout << mp.size() << endl;
		}
	}
	for(int i=1;i<=K;i++)res+=mp[{i,{S,T}}];
	cout<<res<<endl;
}
