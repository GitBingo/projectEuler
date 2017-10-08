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
  //brute force


  string s;
  ll sol = 0;
  while(getline(cin, s))
  {
    vector<ll> nums;
    vector<ll> a;
    vector<ll> b;
    stringstream ss(s);
    ll temp;
    while(ss >> temp)
    {
      nums.push_back(temp);
    }
    good = true;
    permuteIt(nums, 0, a, b);
    if(good)
    {
      ll sum = 0;
      for(ll i = 0; i < nums.size(); i++)
        sum += nums.at(i);
      sol += sum;
    }
  }
  cout << sol << endl;
	
  return 0;
}




