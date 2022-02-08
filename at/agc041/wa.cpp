//agrawal117
//chahatagrawal117
#include <bits/stdc++.h>
#pragma GCC optimize "O3"
#define endl '\n'
using namespace std;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,m,x,p;
    cin>>n>>m>>x>>p;
    vector<ll> v,pre;
    for(int i=0;i<n;i++){
        ll a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    ll sum=0;
    for(int i=0;i<n;i++){
        sum+=v[i];
        pre.push_back(sum);
    }
    int j=n-p;
    int idx=j;
    for(int i=j-1;i>=0;i--){
        if(v[i]==v[j]) idx=i;
        else break;
    }
    // cout<<idx<<endl;
    ll madar=0;
    for(int i=idx-1;i>=0;i--){
        ll val=p-1+i+1;
        val=x-val;
        if(val<0){
            if((v[i]+m)>=v[n-p]) madar++;
            continue;
        } 
        val=val*m;
        ll ans=pre[n-p]-pre[i];
        ll ma=v[i]+m;
        ma=ma*(n-p-i);
        ll space=ma-ans;
        // cout<<v[i]<<" "<<space<<" "<<val<<endl;
        if(space>=val) madar++;
    }
    // cout<<madar<<endl;
    cout<<n-idx+madar<<endl;
    
}
 


