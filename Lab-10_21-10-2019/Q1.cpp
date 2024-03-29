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
    string m,n;
    cin>>m>>n;
    ll k;
    cin>>k;
    map<pll,ll> mp;
    ll rank[k];
    ll size[k];
    ll xcor[k],ycor[k];
    REP(i,0,k)
    {
        ll x,y;
        cin>>x>>y;
        xcor[i]=x;
        ycor[i]=y;
        rank[i]=i;
        size[i]=1;
        mp.insert(MP(MP(x,y),i));
    }
    REP(i,0,k)
    {
        if(mp.count(MP(xcor[i]+1,ycor[i]))!=0) un(size,rank,mp[MP(xcor[i]+1,ycor[i])],i);
        if(mp.count(MP(xcor[i]-1,ycor[i]))!=0) un(size,rank,mp[MP(xcor[i]-1,ycor[i])],i);
        if(mp.count(MP(xcor[i],ycor[i]+1))!=0) un(size,rank,mp[MP(xcor[i],ycor[i]+1)],i);
        if(mp.count(MP(xcor[i],ycor[i]-1))!=0) un(size,rank,mp[MP(xcor[i],ycor[i]-1)],i);
    }
    ll ans=0;
    REP(i,0,k) ans=max(ans,size[i]);
    cout<<ans;

    return 0;
}