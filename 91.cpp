#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll dotProduct(ll x, ll y, ll x2, ll y2)
{
  return x * x2 + y * y2;
}

bool rightTriangle(ll x, ll y, ll x2, ll y2)
{
  if( (x == 0 && y == 0) || (x2 == 0 && y2 == 0))
    return false;
  if(dotProduct(x, y, x2, y2) == 0)
  {
    return true;
  }
  if(dotProduct(x, y, x2 - x, y2 - y) == 0)
  {
    return true;
  }
  if(dotProduct(x2, y2, x2 - x, y2 - y) == 0)
  {
    return true;
  }
  return false;
}

int main()
{
  ll maxT = 50;
  ll sol = 0;
  ll total = 0;
  for(int i = 0; i <= maxT; i++)
  {
    for(int j = 0; j <= maxT; j++)
    {
      for(int k = 0; k <= maxT; k++)
      {
        for(int l = 0; l <= maxT; l++)
        {
          if((i == k && j == l))
            continue;
          
          if(rightTriangle(i, j, k, l))
          {
            sol++;
          }
        }
      }
    }
  }
  cout << sol / 2 << endl;
  return 0;
}




