#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool ispandigital(vector<ll> &nums)
{
  ll digits[10];
  for(int i = 0; i < 10; i++)
  {
    digits[i] = 0;
  }
  for(int i = 0; i < nums.size(); i++)
  {
    ll temp = nums.at(i);
    while(temp > 0)
    {
      digits[temp % 10]++;
      temp /= 10;
    }
  }
  if(digits[0] != 0)
  {
    return false;
  }
  for(int i = 1; i < 10; i++)
  {
    if(digits[i] != 1)
    {
      return false;
    }
  }
  return true;
}

bool isPrime(ll num)
{
  if(num < 2)
  {
    return false;
  }
  ll sqrtN = sqrt(num) + 1;
  if(num % 2 == 0 && num != 2)
  {
    return false;
  }
  for(int i = 3; i <= sqrtN; i+=2)
  {
    if(num % i == 0)
    {
      return false;
    }
  }
  return true;
} 

bool sameButReordered(ll n1, ll n2)
{
	vector<ll> num1;
	vector<ll> num2;
	while(n1 > 0)
	{
		num1.push_back(n1 % 10);
		n1 /= 10;
	}
	while(n2 > 0)
	{
		num2.push_back(n2 % 10);
		n2 /= 10;
	}
	sort(num1.begin(), num1.end());
	sort(num2.begin(), num2.end());
	if(num1.size() != num2.size())
	{
		return false;
	}
	for(int i = 0; i < num1.size(); i++)
	{
		if(num1.at(i) != num2.at(i))
		{
			return false;
		}
	}
	return true;
}

struct nChooseR{

	ll table[1000][1000];

	nChooseR() {
		for(ll i = 0; i < 1000; i++)
		{
			for(ll j = 0; j < 1000; j++)
			{
				table[i][j] = -1;
			}
		}
	}

	ll querry(ll n, ll r)
	{
		if(table[n][r] != -1)
		{
			return table[n][r];
		}
		
		if(n == r)
		{
			return 1;
		}
		if(r == 0)
		{
			return 1;
		}
		ll val = querry(n - 1, r - 1) + querry(n - 1, r);
		table[n][r] = val;
		return val;
	}
	
};


int main()
{
  ll sol = 1;
  for(int i = 0; i < 6; i++)
  {
    sol *= getDigit(pow(10, i));
  
  }
  cout << sol << endl;
   
  return 0;
}
