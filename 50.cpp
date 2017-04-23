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

ll sumInterval(ll start, ll count)
{
	ll total = 0;
	while(count > 0)
	{
		if(isPrime(start))
		{
			count--;
			total += start;
		}
		start++;
	}
	return total;
}

//3+2*1^2
//3 2*7, 5 2*6, 7 2*5, 11 2*3, 13 2*2, 17
int main()
{
  for(ll window = 2; true; window++)
  {
  	//cout << "Test Window " << window << endl;
  	for(int start = 1; start <= 1000000 / window; start++)
  	{
  		ll num = sumInterval(start, window);
  		//cout << "here" << endl;
  		if(num < 1000000 && isPrime(num))
  		{
  			cout << "Window :" << window << " Val:" << num << endl;
  			break;
  		}
  	}
  }
   
  return 0;
}
