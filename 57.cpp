#include <bits/stdc++.h>
#include "InfInt.h"

using namespace std;

typedef InfInt ll;


bool findAproximation(ll iteration)
{
	ll numerator = 1;
	ll denominator = 2;
	ll two = 2;
	
	for(ll i = 1; i < iteration; i++)
	{
		numerator += two * denominator;
		swap(numerator, denominator);
	}
	numerator += denominator;
	numerator = numerator.numberOfDigits();
	denominator = denominator.numberOfDigits();
	if(numerator > denominator)
	{
		return true;
	}
	return false;
}

int main()
{
	ll sol = 0;
	for(int i = 1; i <= 1000; i++)
	{
		if(findAproximation(i))
		{
			sol++;
		}
	}
	cout << sol << endl;
  return 0;
}





