#include <bits/stdc++.h>
#include "InfInt.h"

using namespace std;

typedef InfInt ll;

ll gcd(ll n, ll m)
{
	if(m == 0)
		return n;
	return gcd(m, n %m);
}


ll findX(ll d)
{
  ll sqrtd = d.intSqrt();
  if(sqrtd * sqrtd == d)
  {
    return 0;
  }
	for(ll x = 2; true; x++)
	{
	  ll temp = (x + 1) * (x - 1);
	  if(temp % d != 0)
	  {
	    continue;
	  } 
	  temp /= d;
	  ll sqrtT = temp.intSqrt();
	  if(sqrtT * sqrtT == temp)
	  {
	    return x; 
	  }
	}
	return 0;
}


ll findX2(ll d)
{
  ll sqrtd = d.intSqrt();
  if(sqrtd * sqrtd == d)
  {
    return 0;
  }
	for(ll y = 1; true; y++)
	{
	  ll temp = (ll)1 + d * y * y;
	  ll sqrtT = temp.intSqrt();
	  if(sqrtT * sqrtT == temp)
	  {
	    return sqrtT;
	  }
	  
	}
	return 0;
}

//sqrt((x^2 - 1) / d) = y
//(x+1)(x-1) = d*y*y

//x^2=num
int main()
{
  ll max = 0;
  ll d;
  for(int i = 3; i <= 1000; i++)
  {
    ll found = findX2(i);
    if(found > max)
    {
      max = found;
      d = i;
    }
	  cout << i << " " << found << endl;
  }
  
  cout << "Max: " << max << " d: " << d << endl;
  /*ll num;
  cin >> num;
  cout << findX2(num) << endl;*/
  return 0;
}


