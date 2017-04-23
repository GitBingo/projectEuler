#include <bits/stdc++.h>
#include "InfInt.h"

using namespace std;

typedef InfInt ll;



ll reverse(ll num)
{
	ll temp = 0;
	while(num > 0)
	{
		temp *= 10;
		temp += num % 10;
		num /= 10;
	}
	return temp;
}

bool isPaindrome(ll num)
{
	vector<ll> numbers;
	while(num > 0)
	{
		numbers.push_back(num % 10);
		num /= 10;
	}
	for(int i = 0; i < numbers.size(); i++)
	{
		if(numbers.at(i) != numbers.at(numbers.size() - 1 - i))
		{
			return false;
		}
	}
	return true;
}

bool isLychrel(ll num)
{
	for(int i = 1; i <= 50; i++)
	{
		//cout << num << endl;
		num = num + reverse(num);
		if(isPaindrome(num))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ll sol = 0;
	for(int i = 2; i <= 10000; i++)
	{
		cout << i << " " << sol << endl;
		if(isLychrel(i))
		{
			sol++;
		}
	}
	cout << "Solution " << sol << endl;
  return 0;
}





