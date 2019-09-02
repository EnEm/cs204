#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main()
{
    ll n,q;
    cin>>n>>q;

    ll user_val[n+10];
    REP(i,0,n+10) user_val[i]=0;

    ll max_user_id=-1;

    ll resx,resa,resb;
    REP(i,0,q)
    {
        cin>>resx;
        if(resx==1)
        {
            cin>>resa>>resb;
            user_val[resa]+=resb;
            if(max_user_id==-1)
            {
                max_user_id=resa;
            }
            else if(user_val[max_user_id]<user_val[resa])
            {
                max_user_id=resa;
            }
        }
        else
        {
            if(max_user_id==-1) cout<<"No data available."<<endl;
            else cout<<max_user_id<<endl;
        }
    }

    return 0;
}