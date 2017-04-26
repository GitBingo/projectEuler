#include <bits/stdc++.h>
#include "InfInt.h"


using namespace std;

typedef long long ll;

//1,000,000,000
bool valid(ll num)
{
	for(ll i = 10; i > 0; i--)
	{
		if(num == 0)
		{
			return false;
		}
		//cout << num % 10 << endl;
		if((num / 10) % 10 != i % 10)
		{
			return false;
		}
		num /= 100;
	}
	if(num != 0)
	{
		return false;
	}
	return true;
}



int main()
{
	ll diff = 10000;
	for(ll i = 0; i <= 1000000000; i++)
	{
		//cout << i*i << " " << diff << endl;
		if
		ll temp = i;
		ll build = 1;
		build *= 10;
		build += temp % 10;
		temp /= 10;
		build *= 10;
		build += 2;
		
		build *= 10;
		build += temp % 10;
		temp /= 10;
		build *= 10;
		build += 3;
		
		build *= 10;
		build += temp % 10;
		temp /= 10;
		build *= 10;
		build += 4;
		
		build *= 10;
		build += temp % 10;
		temp /= 10;
		build *= 10;
		build += 5;
		
		build *= 10;
		build += temp % 10;
		temp /= 10;
		build *= 10;
		build += 6;
		
		build *= 10;
		build += temp % 10;
		temp /= 10;
		build *= 10;
		build += 7;
		
		build *= 10;
		build += temp % 10;
		temp /= 10;
		build *= 10;
		build += 8;
		
		build *= 10;
		build += temp % 10;
		temp /= 10;
		build *= 10;
		build += 9;
		
		build *= 10;
		build += temp % 10;
		temp /= 10;
		build *= 10;
		build += 0;
		
		ll tempsqrt = sqrt(build);
		if(tempsqrt * tempsqrt == build)
		{
			cout << tempsqrt << endl;
		}
		/*
		if(valid(i*i))
		{
			cout << i << endl;
			break;
		}*/
	}
	
	
  return 0;
}




