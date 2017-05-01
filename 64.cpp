#include <bits/stdc++.h>



using namespace std;

typedef long long ll;

ll gcd(ll n, ll m)
{
	if(m == 0)
		return n;
	return gcd(m, n %m);
}




ll continuedFraction(ll num, vector<ll> &nums)
{
  ll intPart = sqrt(num);
  
  ll underSqrt = num;
  ll frontSqrt = 1;
  ll added = -1 * intPart;
  ll underFrac = 1;
  
  
  
  for(int i = 0; i < 1000; i++)
  {
		
 		
  	//Flipping fraction
  	ll tempFrontSqrt = underFrac * frontSqrt;
  	ll tempAdded = -1 * underFrac * added;
  	ll tempUnderFrac = underSqrt - added * added;
  	ll commenFactor = gcd(gcd(abs(tempFrontSqrt), abs(tempAdded)), abs(tempUnderFrac));
  	tempFrontSqrt /= commenFactor;
  	tempAdded /= commenFactor;
  	tempUnderFrac /= commenFactor;
  	
  	frontSqrt = tempFrontSqrt;
  	added = tempAdded;
  	underFrac = tempUnderFrac;
  	
  	//Remove Integer
  	ll integerPart = (sqrt((double)underSqrt) + added) / ((double)underFrac);
  	intPart = integerPart;
  	added -= intPart * underFrac;
  	
  	nums.push_back(intPart);
  	
  }
  
}

ll getPeriod(ll num)
{
	vector<ll> info;
	continuedFraction(num, info);
	for(int i = 1; i < 1000; i++)
	{
		bool valid = true;
		for(int j = 0; j < 1000; j++)
		{
			if(info.at(j % i) != info.at(j))
			{
				valid = false;
				break;
			}
		}
		if(valid)
		{
			return i;
		}
	}
	return 0;
}



//x^2=num
int main()
{
	ll sol = 0;
	for(int i = 2; i < 10000; i++)
	{
		ll sqrtI = sqrt(i);
		if(sqrtI * sqrtI == i)
		{
			continue;
		}
		if(getPeriod(i) % 2 == 1)
		{
			sol++;
		}
	}
	cout << sol << endl;
  return 0;
}


