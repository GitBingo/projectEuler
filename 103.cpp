#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool good;

bool valid(vector<ll> &a, vector<ll> &b)
{
  ll sum = 0;
  ll sum2 = 0;
  for(ll i = 0; i < a.size(); i++)
  {
    sum += a.at(i);
  }
  
  for(ll i = 0; i < b.size(); i++)
  {
    sum2 += b.at(i);
  }
  if(sum == sum2 && sum == 0)
    return true; 
  if(sum == sum2)
    return false;
  if(a.size() > b.size() && sum2 > sum)
  {
    return false;
  }
  if(b.size() > a.size() && sum > sum2)
  {
    return false;
  }
  return true;
}


void permuteIt(vector<ll> &nums, ll pos, vector<ll> &a, vector<ll> &b)
{
  if(!good)
    return;
  if(pos == nums.size())
  {
    if(!valid(a,b))
    {
      /*for(ll i = 0; i < a.size(); i++)
        cout << a.at(i) << " ";
      cout << " : ";
      for(ll i = 0; i < b.size(); i++)
        cout << b.at(i) << " ";
      cout << endl;*/
      good = false;
    }
    return;
  }
  permuteIt(nums, pos + 1, a, b);
  a.push_back(nums.at(pos));
  permuteIt(nums, pos + 1, a, b);
  a.pop_back();
  b.push_back(nums.at(pos));
  permuteIt(nums, pos + 1, a, b);
  b.pop_back();
}




int main()
{
  //long story short the string you don't think it is, is the solution

	vector<ll> nums;
	nums.push_back(20);
  nums.push_back(31);
  nums.push_back(38);
  nums.push_back(39);
  nums.push_back(40);
  nums.push_back(42);
  nums.push_back(45);
  
  ll sum = 255;
  ll max = 50;
  for(ll i = 20; i < max; i++)
  {
    nums.at(0) = i;
    cout << i << endl;
    for(ll j = i + 1; j < max; j++)
    {
      nums.at(1) = j;
      
      for(ll k = j + 1; k < max; k++)
      {
        nums.at(2) = k;
        for(ll l = k + 1; l < max; l++)
        {
          nums.at(3) = l;
          for(ll m = l + 1; m < max; m++)
          {
            nums.at(4) = m;
            for(ll n = m + 1; n < max; n++)
            {
              nums.at(5) = n;
              for(ll o = n + 1; o < max; o++)
              {
                nums.at(6) = o;
                
                
                
                vector<ll> a;
	              vector<ll> b;
                good = true;
                ll tSum = 0;
                for(ll p = 0; p < nums.size(); p++)
                {
                  tSum += nums.at(p);
                  //cout << nums.at(p) << " ";
                }
                //cout << endl;
                
                if(tSum > sum)
                  continue;
                permuteIt(nums, 0, a, b);
                if(good)
                {
                  for(ll p = 0; p < nums.size(); p++)
                  {
                    cout << nums.at(p) << " ";
                  }
                  cout << "   :  " << tSum;
                  cout << endl;
                  //ll pause;
                  //cin >> pasue;
                  sum = tSum;
                  
                }
                
              }
            }
          }
        }
      }
    }
  }
  
  
  /*permuteIt(nums, 0, a, b);
  if(good)
    cout << "Valid" << endl;
  else
    cout << "Non-Valid" << endl;*/
  return 0;
}




