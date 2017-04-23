#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll smallPrime(ll num)
{
  if(num < 2)
  {
    return -1;
  }
  ll sqrtN = sqrt(num) + 1;
  if(num % 2 == 0)
  {
    return 2;
  }
  for(int i = 3; i <= sqrtN; i+=2)
  {
    if(num % i == 0)
    {
      return i;
    }
  }
  return num;
}

ll uniquePrimes(ll num)
{
	vector<ll> primeNum;
	while(num > 1)
	{
		ll lFactor = smallPrime(num);
		bool addF = true;
		for(int i = 0; i < primeNum.size(); i++)
		{
			if(primeNum.at(i) == lFactor)
			{
				addF = false;
				break;
			}
		}
		if(addF)
		{
			primeNum.push_back(lFactor);
		}
		num /= lFactor;
	}
	return primeNum.size();

}


//3+2*1^2
//3 2*7, 5 2*6, 7 2*5, 11 2*3, 13 2*2, 17
int main()
{
  for(int i = 3; true; i++)
  {
  	if(uniquePrimes(i) == 4 && 
  			uniquePrimes(i + 1) == 4 &&
  			uniquePrimes(i + 2) == 4 &&
  			uniquePrimes(i + 3) == 4)
  	{
  		cout << i << endl;
  		break;
  	}
  }
   
  return 0;
}
