#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool isInt(ll a, ll b, ll c)
{
  ll val1 = a*a + (b+c)*(b+c);
  ll val2 = (a+b)*(a+b) + c*c;
  ll val3 = (a+c)*(a+c) + b*b;
  ll val = min(min(val1, val2), val3);
  ll sqVal = sqrt(val);
  //cout << sqVal << endl;
  if(sqVal * sqVal == val)
  {
    
    return true;
  }
  return false;
}

ll findSize()
{
  ll sol = 0;
  ll i = 1;
  for(; sol < 1000000; i++)
  {
    cout << i << " " << sol << endl;
    for(int j = 1; j <= i; j++)
    {
      for(int k = 1; k <= j; k++)
      {
        if(isInt(i,j,k))
        {
          sol++;
        }
      }
    }
  }
  return i - 1;
}

int main()
{
  //cout << isInt(3, 5, 6) << endl;
  /*cout << findSize(99) << endl;
  ll i = 100;
  for(; findSize(i) < 1000000; i++)
  {
    cout << i << " " << findSize(i) << endl;
  }
  cout << i << endl;*/
  cout << findSize() << endl;
  return 0;
}




