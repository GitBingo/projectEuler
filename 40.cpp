#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll getDigit(ll pos)
{
  ll currDigit = 0;
  ll curr = 1;
  while(pos > 0)
  {
    ll temp = curr;
    for(int i = 0; pos > 0 && temp > 0; i++)
    {
      currDigit = (curr / (ll)pow((ll)10, (ll)(ceil(log10(curr + 1)) - 1 - i))) % 10 ;
      //cout << (curr / (ll)pow((ll)10, (ll)(ceil(log10(curr + 1)) - 1 - i))) % 10 << endl;;
      temp /= 10;
      pos--;
    }
    curr++;
  }
  return currDigit;
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
