#include<iostream>
#define ll long long

bool check_prime(ll n)
{
	bool flag=1;
	for(ll i=2;(i*i)<=n;i++)
	{
		if((n%i)==0)
		{
			flag=0;
			break;
		}
	}
	return flag;
}

int main(void)
{
    ll t;
    scanf("%lld",&t);
    bool flag=check_prime(t);
    printf("%d",flag);
    /*
    if(flag==0) printf("The number is not prime!\n\n");
    else printf("The number is prime!\n\n");
	*/
    return 0;
}