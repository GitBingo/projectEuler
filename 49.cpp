#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


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

bool same(ll n1, ll n2)
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

//3+2*1^2
//3 2*7, 5 2*6, 7 2*5, 11 2*3, 13 2*2, 17
int main()
{
  for(int i = 1000; i <= 9999; i++)
  {
  	if(same(i, i + 3330) && same(i, i + 2*3330) &&
  		isPrime(i) && isPrime(i + 3330) && isPrime(i + 2*3330))
  		{
  			cout << i << i+3330 << i + 2*3330 << endl;
  		}
  }
   
  return 0;
}
