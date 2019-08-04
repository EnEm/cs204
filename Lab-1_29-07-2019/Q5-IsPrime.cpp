#include<iostream>
using namespace std;
#define ll long long

ll string_size(char *s)
{
	ll t=0;
	while((*(s++))!='\0')
	{
		t++;
	}
	return t;
}

void string_reverse(char *a)
{
	ll n=string_size(a);
	char c;
	for(int i=0;i<n/2;i++)
	{
		c=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=c;
	}
}

void string_adder(char *a,char *b,int f,char *ans,int *flag)
{
	ll na=string_size(a);
	string_reverse(a);
	ll nb=string_size(b);
	string_reverse(b);
	ll mxx;
	if(na>nb) mxx=na;
	else mxx=nb;
	ll carry=f;
	int i;
	for(i=0;i<mxx;i++)
	{
		ll t=carry;
		if(i<na) t+=(a[i]-'0');
		if(i<nb&&f==0) t+=(b[i]-'0');
		else if(i<nb&&f==1) t+=(9-(b[i]-'0'));
		else if(f==1) t+=9;
		ans[i]=(t%10+'0');
		carry=t/10;
	}
	if(carry==0&&f==1)
	{
		*flag=1;
	}
	if(f==0)
	{
		while(carry>0)
		{
			ans[i]=carry%10+'0';
			carry/=10;
			i++;
		}
	}
	ans[i]='\0';
	string_reverse(ans);
	string_reverse(a);
	string_reverse(b);
	return ;
}

void string_dividor(char *a,char*b,ll na,ll nb,char *ans1,char *ans2)
{
	char f[10][nb+5];
	char t[1005];
	f[0][0]='\0';
	ll fn[10];
	fn[0]=0;
	int flag=0;
	for(ll i=1;i<10;i++)
	{
		string_adder(b,f[i-1],0,f[i],&flag);
		fn[i]=string_size(f[i]);
	}
	ans2[0]='\0';
	char temp[1005];
	temp[0]='\0';
	for(ll i=0;i<na;i++)
	{
		ll ntt=string_size(temp);
		temp[ntt]=a[i];
		temp[ntt+1]='\0';
		for(ll j=9;j>=0;j--)
		{
			flag=0;
			string_adder(temp,f[j],1,ans2,&flag);
			if(flag==0)
			{
				ll nt=string_size(ans2);
				for(ll j=0;j<nt;j++)
				{
					temp[j]=ans2[j];
				}
				temp[nt]='\0';
				ans1[i]=j+'0';
				break;
			}
		}
	}
	ans1[na]='\0';
	return;
}

void string_multiplier(char *a,char *b,ll na,ll nb,char* ans)
{
	string_reverse(a);
	ans[0]='\0';
	ll n=0;
	char f[10][na+1];
	char t[2005];
	f[0][0]='\0';
	ll fn[10];
	fn[0]=0;
	int flag=0;
	for(ll i=1;i<10;i++)
	{
		string_adder(a,f[i-1],0,f[i],&flag);
		fn[i]=string_size(f[i]);
	}
	for(ll i=0;i<nb;i++)
	{
		ll j=0;
		for(;j<i;j++)
		{
			t[j]='0';
		}
		for(j
		;j<fn[b[i]-'0']+i;j++)
		{
			t[j]=f[b[i]-'0'][j-i];
		}
		t[j]='\0';
		string_adder(ans,t,0,ans,&flag);
		n=string_size(ans);
	}
	string_reverse(ans);
	string_reverse(b);
	return;
}

bool check_prime(char *s)
{
	ll n=string_size(s);
	if(n==1&&s[0]=='1') return 0;
	if(n==1&&s[0]=='2') return 1;
	bool ans=1;
	char i[1005];
	char ans1[1005];
	char ans2[1005];
	char ans3[1005];
	char ans4[1005];
	char temp[2];
	temp[0]='1';
	temp[1]='\0';
	i[0]='2';
	i[1]='\0';
	int flag=0;
	ll ni=1;
	for(;;)
	{
		string_dividor(s,i,n,ni,ans1,ans2);
		char * t=ans2;
		while(*t=='0') t++;
		if(*t=='\0')
		{
			ans=0;
			break;
		}
		string_adder(i,temp,0,i,&flag);
		string_reverse(i);
		ni=string_size(i);
		string_multiplier(i,i,ni,ni,ans3);
		string_adder(s,ans3,1,ans4,&flag);
		if(flag==1)
		{
			break;
		}
	}
	return ans;
}

int main(void)
{
	ll q;
	cin>>q;
	while(q--)
	{
		char t[1005];
		scanf("%s",t);
		bool flag=check_prime(t);
		if(flag==0) printf("Not a Prime\n");
		else printf("Prime\n");
	}
	return 0;
}
