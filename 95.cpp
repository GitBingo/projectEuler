#include <bits/stdc++.h>
#include <unordered_map>


using namespace std;

typedef long long ll;



ll sumDivisors(ll n)
{
  ll sol = 1;
  ll sqrtN = sqrt(n);
  for(ll i = 2; i < sqrtN; i++)
  {
    if(n % i == 0)
    {
      sol += i;
      sol += n / i;
    }
  }
  if(n % sqrtN == 0)
  {
    sol += sqrtN;
  }
  return sol;
}



int main()
{
  cout << sumDivisors(16) << endl;
  //std::map<ll,bool> first;
  ll sol = 0;
  ll len = 0;
  for(int i = 2; i <= 1000000; i++)
  {
    ll test = i;
    ll length = 0;
    bool bad = false;
    if(i % 100000 == 0)
      cout << i << endl;
    ll maxLength = 1000;
    while(true)
    {
      test = sumDivisors(test);
      //cout << test << endl;
      /*if(first.find(test) != first.end())
      {
        break;
      }
      first[test] = true;*/
      
      if(length > maxLength)
      {
        bad = true;
        break;
      }
      
      if(test > 1000000)
      {
        bad = true;
        break;
      }
      if(test == i)
      {
        break;
      }
      length++;
    }
    if(!bad)
    {
      if(length > len)
      {
        len = length;
        sol = i;
      }
    }
  }
  cout << sol << endl;
  
  return 0;
}




