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

bool found;
ll sol = 0;

ll permuteIt(vector<bool> &used, ll max, ll pos, ll num)
{
  if(max == pos)
  {
    if(isPrime(num))
    {
      if(num > sol)
      {
        sol = num;
      }
      cout << num << " Solution :" << sol << endl;
    }
    return 0;
  }
  for(int i = 0; i < used.size(); i++)
  {
    if(!used[i])
    {
      used[i] = true;
      num *= 10;
      num += max - i;
      permuteIt(used, max, pos + 1, num);
      num /= 10;
      used[i] = false;
    } 
  }
}


int main()
{
  ll sol = 1;
  ll sizePandigital = 4;

  for(int sizePandigital = 2; sizePandigital < 10; sizePandigital++)
  {
    vector<bool> used(sizePandigital, false);
    found = false;
    permuteIt(used, sizePandigital, 0, 0);
  }
  
  /*for(int i = 999999999; i > 0; i-=2)
  {
    vector<ll> aNum;
    aNum.push_back(i);
    cout << i << endl;
    if(ispandigital(aNum) && isPrime(i))
    {
      cout << i << endl;
      break;
    }
  
  }*/
  //cout << sol << endl;
   
  return 0;
}
