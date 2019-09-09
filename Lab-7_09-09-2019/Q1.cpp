#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

bool comp(string &x,string &y)
{
    
}

int main()
{
    ll tc;
    cin>>tc;

    while(tc--)
    {
        ll n;
        cin>>n;

        string a[n];
        REP(i,0,n)
        {
            cin>>a[i];
        }

        sort(a,a+n,comp);

        REP(i,0,n)
        {
            cout<<a[i];
        }
        cout<<'\n';
    }

    return 0;
}