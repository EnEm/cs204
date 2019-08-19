#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define REPI(i,a,b) for(ll i=b-1;i>=a;i--)
#define PB push_back

struct coord
{
    ll x;
    ll y;
};

struct node
{
    coord dat;
    node * ptr;
};
node* top;

void AddFirst(ll x,ll y)
{
    node* temp=(node*)(malloc(sizeof(node)));
    temp->dat.x=x;
    temp->dat.y=y;
    temp->ptr=top;
    top=temp;
    return;
}

void DelFirst()
{
    if(top==NULL)
    {
        cout<<-1<<'\n';;
    }
    else
    {
        node* temp=(top->ptr);
        free(top);
        top=temp;
    }
    return;
}

void Del(ll x,ll y)
{
    node * it=top;
    node * pr=NULL;
    while(it!=NULL)
    {
        if(it->dat.x==x&&it->dat.y==y)
        {
            if(pr!=NULL)
            {
                pr->ptr=it->ptr;
            }
            else
            {
                top=it->ptr;
            }
            free(it);
            return;
        }
        else
        {
            pr=it;
            it=it->ptr;
        }
    }
    cout<<-1<<'\n';
    return;
}

void Search(double d)
{
    d*=d;
    node * it=top;
    ll flag=0;
    while(it!=NULL)
    {
        if(it->dat.x*it->dat.x+it->dat.y*it->dat.y<=d)
        {
            flag=1;
            cout<<'('<<it->dat.x<<','<<it->dat.y<<')';
        }
        it=it->ptr;
    }
    if(flag==0) cout<<-1;
    cout<<'\n';
    return;
}

void Search(ll x,ll y)
{
    node * it=top;
    while(it!=NULL)
    {
        if(it->dat.x==x&&it->dat.y==y)
        {
            cout<<"True"<<'\n';
            return;
        }
        else
        {
            it=it->ptr;
        }
    }
    cout<<"False"<<'\n';
    return;
}

void Length()
{
    ll cnt=0;
    node * it=top;
    while(it!=NULL)
    {
        cnt++;
        it=it->ptr;
    }
    cout<<cnt<<'\n';
    return;
}

int main()
{
    top=NULL;
    ll q;
    cin>>q;
    while(q--)
    {
        ll qt;
        cin>>qt;
        ll x,y;
        double f;
        switch(qt)
        {
            case 1:
                cin>>x>>y;
                AddFirst(x,y);
                break;
            case 2:
                DelFirst();
                break;
            case 3:
                cin>>x>>y;
                Del(x,y);
                break;
            case 4:
                cin>>f;
                Search(f);
                break;
            case 5:
                cin>>x>>y;
                Search(x,y);
                break;
            case 6:
                Length();
                break;
            default:
                break;
        }
    }
    return 0;
}