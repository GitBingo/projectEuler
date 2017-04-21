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
