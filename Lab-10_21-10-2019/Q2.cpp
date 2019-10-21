#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define V(a) vector<a>
#define MP make_pair
#define REP(i,a,b) for(ll i=a;i<b;i++)

ll find(ll rank[],ll x)
{
    if(rank[x]==x) return x;
    else return rank[x]=find(rank,rank[x]);
}

void un(ll size[],ll rank[],ll x,ll y)
{
    x=find(rank,x);
    y=find(rank,y);
    if(x==y) return;
    if(size[x]<size[y]) swap(x,y);
    size[x]+=size[y];
    rank[y]=x;
    return;
}

int main()
{
    ll m,n,c;
    cin>>m>>n>>c;
    ll mp[m*n];
    ll rank[m*n];
    ll size[m*n];
    REP(i,0,m)
    {
        REP(j,0,n)
        {
            cin>>mp[i*n+j];
            rank[i*n+j]=i*n+j;
            size[i*n+j]=1;
        }
    }
    REP(i,0,m)
    {
        REP(j,0,n)
        {
            if(i!=0) if(mp[i*n+j-n]==mp[i*n+j]) un(size,rank,i*n+j-n,i*n+j);
            if(i!=m-1) if(mp[i*n+j+n]==mp[i*n+j]) un(size,rank,i*n+j+n,i*n+j);
            if(j!=0) if(mp[i*n+j-1]==mp[i*n+j]) un(size,rank,i*n+j-1,i*n+j);
            if(j!=n-1) if(mp[i*n+j+1]==mp[i*n+j]) un(size,rank,i*n+j+1,i*n+j);
        }
    }
    ll ans=0;
    ll anc=0;
    REP(i,0,m)
    {
        REP(j,0,n)
        {
            if(size[i*n+j]>ans)
            {
                ans=size[i*n+j];
                anc=mp[i*n+j];
            }
        }
    }
    cout<<ans<<' '<<anc;

    return 0;
}