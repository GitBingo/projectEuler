#include <bits/stdc++.h>
#include "InfInt.h"


using namespace std;

typedef InfInt ll;

// off by one


ll validNum(ll num)
{
	ll temp = num;
	ll total = 0;
	for(int i = 1; temp.numberOfDigits() < 29; i++)
	{
		//cout << "I " << i << endl;
		if(temp.numberOfDigits() == i)
		{
			cout << temp << endl;
			//cout << temp << endl;
			total++;
		}
		temp *= num;
	}
	return total;
}


int main()
{
	//cout << validNum(7) << endl;
	//return 0;
	ll sol = 0;
	for(int i = 2; i < 10; i++)
	{
		sol += validNum(i);
	}
		cout << sol << endl;
  return 0;
}


