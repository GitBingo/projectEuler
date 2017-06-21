#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll sol(ll x, ll y)
{
    return ((x * (x + 1)) / 2) * ((y * (y + 1)) / 2);
}



int main()
{
  ll diff = 2000000;
  ll area = 0;
  for(int i = 1; i < 10000; i++)
  {
    for(int j = 1; j < 10000; j++)
    {
        if(abs(sol(i, j) - 2000000) < diff )
        {
            diff = abs(sol(i, j) - 2000000);
            cout << i << " " << j << endl;
            area = i * j;
        }
    }
  }
  cout << diff << endl;
  cout << area << endl;
  return 0;
}
