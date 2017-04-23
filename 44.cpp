#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool isPentagonal(ll num)
{
	ll curr = 0;
	for(ll i = 1; curr <= num; i++)
	{
		curr = (i*(3*i - 1)) / 2;
		if(num == curr)
		{
			return true;
		}
	}
	return false;
}



int main()
{
  
  ll smallest = 99999999;
  
  for(ll i = 2; i < 10000; i++)
  {
  	for(ll j = 1; j < i; j++)
  	{
  		ll iTemp = (i * (3 * i-1)) / 2;
  		ll jTemp = (j * (3 * j-1)) / 2;
  		if(isPentagonal(iTemp - jTemp) && isPentagonal(iTemp + jTemp))
  		{
  			cout << i << " " << j << " " << iTemp - jTemp << endl;
  			if(iTemp - jTemp < smallest)
  			{
  				smallest = iTemp - jTemp;
  			}
  		}
  	}
  }
  cout << smallest << endl;
   
  return 0;
}
