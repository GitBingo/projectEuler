#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isAllDigits(vector<ll> &nums)
{
  ll digits[10];
  for(int i = 0; i < 10; i++)
  {
    digits[i] = 0;
  }
  for(int i = 0; i < nums.size(); i++)
  {
    ll temp = nums.at(i);
    while(temp > 0)
    {
      digits[temp % 10]++;
      temp /= 10;
    }
  }
  if(digits[0] != 0)
  {
    return false;
  }
  for(int i = 1; i < 10; i++)
  {
    if(digits[i] != 1)
    {
      return false;
    }
  }
  return true;
}


bool over(vector<ll> &nums)
{
  ll count = 0;
  for(int i = 0; i < nums.size(); i++)
  {
    ll temp = nums.at(i);
    while(temp > 0)
    {
      count++;
      temp /= 10;
    }
    
  }
  
  if(count <= 10)
  {
    //cout << "Count1 " << count << " " << nums.size() << endl;
    return false;
  }
  //cout << "Count2 " << count << endl;
  return true;
}

ll panDigital(ll n)
{
  vector<ll> nums;
  
  for(int i = 1; !over(nums); i++)
  {
    if(isAllDigits(nums))
    {
      ll sol = 0;
      for(int j = 0; j < nums.size(); j++)
      {
        sol *= pow(10, ceil(log10(nums.at(j))));
        sol += nums.at(j);
      }
      return sol;
    }
    //cout << i*n << endl;
    nums.push_back(i * n);
  }
  return -1;
}

int main()
{
  
  
  ll num = 2;
  ll largest = 0;
  while(true)
  {
    ll temp = panDigital(num);
    if(temp != -1)
    {
      if(temp > largest)
      {
        largest = temp;
      }
      cout << num << " " << largest << endl;
    }
    num++;
  }
  return 0;
}
