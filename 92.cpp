#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

bool chain(ll num)
{
  if(num == 89)
  {
    return true;
  }
  if(num == 1)
  {
    return false;
  }
  ll sum = 0;
  while(num > 0)
  {
    sum += (num % 10) * (num % 10);
    num /= 10;
  }
  return chain(sum);
}

int main()
{
  ll count = 0;
  for(int i = 1; i < 10000000; i++)
  {
    if(chain(i))
    {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}




