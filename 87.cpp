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
  vector<ll> hit(55000000, 0);
  ll max = 50000000;
  for(int i = 2; i*i <= max; i++)
  {
    if(!isPrime(i))
      continue;
    for(int j = 2; j*j*j <= max; j++)
    {
      if(!isPrime(j))
        continue;
      for(int k = 2; k*k*k*k <= max; k++)
      {
        if(!isPrime(k))
          continue;
        if(i*i + j*j*j + k*k*k*k <= max)
        {
          //cout << i << " " << j << " " << k << " " << i*i + j*j*j + k*k*k*k << endl;
          hit.at(i*i + j*j*j + k*k*k*k) = 1;
        }
      }
    }
  }
  ll sol = 0;
  for(int i = 0; i <= max; i++)
  {
    if(hit.at(i) == 1)
    {
      sol++;
    }
  }
  cout << sol << endl;
  return 0;
}




