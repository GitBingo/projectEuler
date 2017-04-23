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


int main()
{
	ll sol = 0;
	ll diff = 2;
	ll num = 1;
	
	ll total = 1;
	ll isPrimeNum = 0;
	
	for(int i = 1; true; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			num += diff;
			total++;
			if(isPrime(num))
			{
				isPrimeNum++;
			}
		}
		if(isPrimeNum / (double)total < .1)
		{
			cout << diff + 1 << endl;
			break;
		}
		
		diff += 2;
	}
  return 0;
}




