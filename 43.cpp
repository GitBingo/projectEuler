#include <bits/stdc++.h>

using namespace std;

typedef long long ll;



bool found;
ll sol = 0;


bool validNum(ll num)
{
	if(((num / (ll)pow(10, 6)) % (ll)1000) % 2 == 0 &&
			((num / (ll)pow(10, 5)) % (ll)1000) % 3 == 0 &&
			((num / (ll)pow(10, 4)) % (ll)1000) % 5 == 0 &&
			((num / (ll)pow(10, 3)) % (ll)1000) % 7 == 0 &&
			((num / (ll)pow(10, 2)) % (ll)1000) % 11 == 0 &&
			((num / (ll)pow(10, 1)) % (ll)1000) % 13 == 0 &&
			((num / (ll)pow(10, 0)) % (ll)1000) % 17 == 0	 )
	{
	
		return true;
	}
	return false;

}

ll permuteIt(vector<bool> &used, ll max, ll pos, ll num)
{
	//cout << "Here" << endl;
  if(max == pos)
  {
  	if(num > 99999999 && validNum(num))
  	{
  		sol += num;
    	cout << num << endl;
    }
    return 0;
  }
  for(int i = 0; i < used.size(); i++)
  {
    if(!used[i])
    {
      used[i] = true;
      num *= 10;
      num += max - i - 1;
      permuteIt(used, max, pos + 1, num);
      num /= 10;
      used[i] = false;
    } 
  }
}


int main()
{
  sol = 0;
  ll sizePandigital = 4;

  for(int sizePandigital = 10; sizePandigital < 11; sizePandigital++)
  {
    vector<bool> used(sizePandigital, false);
    found = false;
    permuteIt(used, sizePandigital, 0, 0);
  }
  cout << "Solution :" << sol << endl;
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
