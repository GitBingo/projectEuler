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

bool trucatablePrime(ll num)
{
  ll temp = num;
  while(temp > 0)
  {
    if(!isPrime(temp))
    {
      return false;
    }
    temp /= 10;
  }
  temp = num;
  while(temp > 0)
  {
    if(!isPrime(temp))
    {
      return false;
    }
    //cout << temp << endl;
    temp %= (int)pow(10, (int)(ceil(log10(temp)) - 1));
  }
  return true;
}

int main()
{
  trucatablePrime(1234);
  ll num = 11;
  ll total = 0;
  for(ll num = 11; true; num+=2 )
  {
    if(trucatablePrime(num))
    {
      total += num;
      cout << num << " " << total << endl;
    }
  }
  return 0;
}
