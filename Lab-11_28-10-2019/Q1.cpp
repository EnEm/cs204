#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define V(a) vector<a>
#define PB push_back
#define pll pair<ll,ll>
#define MP make_pair
#define F first
#define S second

bool dfs(ll x,ll color[],V(ll) ad[])
{
    bool ans=1;
    for(auto y:ad[x])
    {
        if(color[y]==color[x]) ans=0;
        else if(color[y]==-1)
        {
            color[y]=(color[x]+1)%2;
            ans&=dfs(y,color,ad);  
        }
    }
    return ans;
}

int main()
{
    string n;
    ll m;
    cin>>n>>m;
    string u[m],v[m];
    map<string,ll> node;
    ll node_size=0;
    REP(i,0,m)
    {
        cin>>u[i]>>v[i];
        if(node.count(u[i])==0)
        {
            node.insert(MP(u[i],node_size));
            node_size++;
        }
        if(node.count(v[i])==0)
        {
            node.insert(MP(v[i],node_size));
            node_size++;
        }
    }
    V(ll) ad[node_size];
    REP(i,0,m)
    {
        ad[node[u[i]]].PB(node[v[i]]);
        ad[node[v[i]]].PB(node[u[i]]);
    }
    ll color[node_size];
    REP(i,0,node_size)
    {
        color[i]=-1;
    }
    bool ans=1;
    REP(i,0,node_size)
    {
        if(color[i]==-1) 
        {
            color[i]=0;
            ans&=dfs(i,color,ad);
        }
    }
    if(ans==1) cout<<"YES\n";
    else cout<<"NO\n";

    return 0;
}