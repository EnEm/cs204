#include<iostream>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main()
{
    ll q;
    cin>>q;
    while(q--)
    {
        string s;
        cin>>s;
        ll n=s.size();
        char stck[n];
        ll stcksize=0;
        ll flag=0;
        REP(i,0,n)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='['||s[i]=='<')
            {
                stck[stcksize]=s[i];
                stcksize++;
            }
            else if(s[i]==')'||s[i]=='}'||s[i]==']'||s[i]=='>')
            {
                if(s[i]==')')
                {
                    if(stcksize==0)
                    {
                        flag=1;
                        break;
                    }
                    else if(stck[stcksize-1]=='(')
                    {
                        stcksize--;
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                else if(s[i]=='}')
                {
                    if(stcksize==0)
                    {
                        flag=1;
                        break;
                    }
                    else if(stck[stcksize-1]=='{')
                    {
                        stcksize--;
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                else if(s[i]==']')
                {
                    if(stcksize==0)
                    {
                        flag=1;
                        break;
                    }
                    else if(stck[stcksize-1]=='[')
                    {
                        stcksize--;
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
                else if(s[i]=='>')
                {
                    if(stcksize==0)
                    {
                        flag=1;
                        break;
                    }
                    else if(stck[stcksize-1]=='<')
                    {
                        stcksize--;
                    }
                    else
                    {
                        flag=1;
                        break;
                    }
                }
            }
            else if(s[i]=='|')
            {
                if(stcksize!=0)
                {
                    if(stck[stcksize-1]=='|')
                    {
                        stcksize--;
                    }
                    else
                    {
                        stck[stcksize]=s[i];
                        stcksize++;
                    }
                }
                else
                {
                    stck[stcksize]=s[i];
                    stcksize++;
                }
            }
            else
            {
                flag=1;
                break;   
            }
        }
        if(flag==0&&stcksize==0)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }

    return 0;
}