#include <bits/stdc++.h>
#include <unordered_map>


using namespace std;

typedef long long ll;




bool valid(ll b, ll a)
{
  if(b * 2 + a > 1000000000)
  {
    return false;
  }
  if((a * a) % 4 != 0)
  {
    return false;
  }
  ll h = (b * b) - (a * a) / 4;
  ll sqrtH = (ll)sqrt(h);
  if(sqrtH * sqrtH != h)
  {
    return false;
  }
  
  h = sqrtH;
  if(sqrtH % 2 == 0 ||  a % 2 == 0)
  {
    return true;
  }
  return false;
}

int main()
{
  ll sol = 0;
  for(int i = 2; i <= 1000000000; i++)
  {
    if(i % 100000000 == 0)
      cout << i << endl;
    if(valid(i, i + 1))
    {
      cout << i << " " << i + 1 << endl;
      sol+= 2 * i + (i+1);
    }
    if(valid(i, i - 1))
    {
      cout << i << " " << i - 1 << endl;
      sol+=2 * i + (i-1);
    }
  }
  cout << sol << endl;
  //ll num = 15241578750190521;
  //cout << num << endl;
  //cout << (ll)sqrt(num) << endl;
  cout << valid(5,6) << endl;
  
  
  return 0;
}




