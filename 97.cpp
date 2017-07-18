#include <bits/stdc++.h>
#include <unordered_map>
#include "InfInt.h"

using namespace std;

typedef InfInt ll;


ll fastPow(ll n, ll m, ll mod)
{
  //cout << n << endl;
  if(m == 1)
    return n;
  if(m == 0)
    return 1;
  if(m % 2 == 0)
  {
    ll sol = fastPow(n, m / 2, mod);
    return (sol * sol) % mod;
  }
  return (n * fastPow(n, m - 1, mod)) % mod;
}


int main()
{
  //cout << fastPow(5,4,10000000000) << endl;
  ll one = 1;
  ll front = 28433;
  cout << (front * fastPow(2,7830457, 10000000000) + one) % 10000000000 << endl;
  return 0;
}




