#include <bits/stdc++.h>
#include "InfInt.h"
using namespace std;

typedef InfInt ll;

bool valid(ll num)
{
	vector<ll> temp2;
	for(ll i = 1; i < 10; i++)
	{
		temp2.push_back(num % 10);
		num /= 10;
	}
	sort(temp2.begin(), temp2.end());
	for(int i = 0; i < 9; i++)
	{
		if((ll)(i+1) != temp2.at(i))
			return false;
	}
	return true;
}

bool valid1(ll num2)
{
	if(num2.size() < 20)
		return false;
	string s = num2.toString();
	ll num = 0;
	for(int i = 1; i < 10; i++)
	{
		num *= 10;
		num+= (ll)(s.at(s.size() - i) - '0');
	}
	return valid(num);
}

bool valid2(ll num2)
{
	if(num2.size() < 20)
		return false;
	string s = num2.toString();
	ll num = 0;
	for(int i = 1; i < 10; i++)
	{
		num *= 10;
		num+= (ll)(s.at(i - 1) - '0');
	}
	return valid(num);
}

int main()
{
	ll one = "1";
	ll two = 1;
	//infinite size numbers and then start at 1,1
	//and just walk up
	for(ll i = 2; true; i++)
	{
		//cout << two << endl;
		//cout << two.numberOfDigits() << endl;
		bool set2 = valid2(two);
		bool set1 = valid1(two);
		if(set2)
		{
			cout << "Start " << i << endl;
			//break;
		}
		if(set1)
		{
			cout << "                           Stop " << i << endl;
			//break;
		}
		if(set1 && set2)
		{
			break;
		}
		ll temp = one;
		one = two;
		two += temp;
	}
  return 0;
}




