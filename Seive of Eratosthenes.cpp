//sieve of eratosthenes or prime of sieve
#include<iostream>
#include<math.h>
using namespace std;
void primeofsieve(long long int n)
{
	long long int arr[n]={};
	for(int i=2;i<=sqrt(n);i++)
	{
		for(long long int j=i*i;j<=n;j+=i)
			arr[j]=1;
	}
	for(long long int i=2;i<=n;i++)
	{
	    if(arr[i]==0)
	    	cout<<i<<" ";
	}


}
int main()
{

	#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    #endif
	long long int n;
	cin>>n;
	cout<<"PRIME NUMBERs ARE : ";
	primeofsieve(n);
	return 0;
}

