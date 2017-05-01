#include <bits/stdc++.h>
#include "InfInt.h"


using namespace std;

typedef InfInt ll;

ll gcd(ll n, ll m)
{
	if(m == 0)
		return n;
	return gcd(m, n %m);
}


ll getNum(ll num)
{
	if(num < 2)
	{
		return 1;
	}
	if((num  - 2) % 3 == 0)
	{
		return (((num - 2) / 3) + 1) * 2;
	}
	return 1;
}

void continuedFraction(ll num)
{
  num--;
  
  ll numerator = 1, denomenator = getNum(num);
  
  for(ll i = num - 1; i > 0; i--)
  {
		//cout << numerator << " " << denomenator << endl;
 		numerator += denomenator * getNum(i);
 		swap(numerator, denomenator);
 		ll commonFactor = gcd(numerator, denomenator);
  	numerator /= commonFactor;
  	denomenator /= commonFactor;
  	
  }
  ll two = 2;
  numerator = numerator + two * denomenator;
  cout << numerator << " " << denomenator << endl;
  ll val = 0;
  for(int i = 0; i < numerator.numberOfDigits(); i++)
  {
  	val += numerator.digitAt(i);
  }
  cout << val << endl;;
}




//x^2=num
int main()
{
	continuedFraction(100);
  return 0;
}


