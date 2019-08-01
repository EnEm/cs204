#include<iostream>
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

void string_adder(char *a,char *b,int f,char *ans,int *flag,ll na,ll nb)
{
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
	return ;
}

void string_multiplier(char *a,char *b,ll na,ll nb,char* ans)
{
	ans[0]='\0';
	ll n=0;
	char f[10][na+1];
	char t[2000005];
	f[0][0]='\0';
	ll fn[10];
	fn[0]=0;
	int flag=0;
	for(ll i=1;i<10;i++)
	{
		string_adder(a,f[i-1],0,f[i],&flag,na,fn[i-1]);
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
		string_adder(ans,t,0,ans,&flag,n,fn[b[i]-'0']+i);
		n=string_size(ans);
	}
	return;
}

int main(void)
{
	static char a[1000005],b[1000005],ans[2000020];
    scanf("%s",a);
    scanf("%s",b);
	ll na=string_size(a);
	ll nb=string_size(b);
	string_reverse(a);
	string_reverse(b);
    string_multiplier(a,b,na,nb,ans);
	string_reverse(ans);
	char *t=ans;
	while(*t=='0') t++;
	if(*t=='\0') printf("0\n");
    else printf("%s\n",t);

	return 0;
}