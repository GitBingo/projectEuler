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

bool checkPrime(ll num, ll prime)
{

	ll check = prime;
	
	for(int i = 1; check <= num; i++)
	{
		check = prime + 2*i*i;
		if(check == num)
		{
			return true;
		}
	}
	return false;
}


bool loopPrimes(ll num)
{
	if(checkPrime(num, 2))
	{
		return true;
	}
	for(int i = 3; i <= num; i+=2)
	{
		if(isPrime(i) && checkPrime(num, i))
		{
			return true;
		}
	}
	return false;

}
//3+2*1^2
//3 2*7, 5 2*6, 7 2*5, 11 2*3, 13 2*2, 17
int main()
{
  for(int i = 3; true; i+=2)
  {
  	if(!isPrime(i) && !loopPrimes(i))
  	{
  		cout << i << endl;
  		break;
  	}
  }
   
  return 0;
}
