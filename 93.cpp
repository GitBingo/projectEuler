#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

vector<bool> valid;

vector<double> setN;

ll solution;
ll largest;

void callFunction(double l)
{
  //cout << l << endl;
  if(((ll)l) == l && l >= 0)
  {
    valid.at((ll)l) = true;
  }
}

double joinNums(double num1, double num2, double expr)
{
  if(expr == 0)
  {
    return num1 + num2;
  }
  if(expr == 1)
  {
    return num1 - num2;
  }
  if(expr == 2)
  {
    return num1 * num2;
  }
  if(expr == 3)
  {
    if(num2 == 0)
      return 0;
    return num1 / num2;
  }
  return 0;
}


void casses(vector<double> &expre, vector<ll> &nums)
{
  //case1
  double num1 = joinNums(setN.at(nums.at(0)), setN.at(nums.at(1)), expre.at(0));
         num1 = joinNums(num1, setN.at(nums.at(2)), expre.at(1));
         num1 = joinNums(num1, setN.at(nums.at(3)), expre.at(2));
         callFunction(num1);
         
         num1 = joinNums(setN.at(nums.at(1)), setN.at(nums.at(2)), expre.at(1));
         num1 = joinNums(setN.at(nums.at(0)), num1, expre.at(0));
         num1 = joinNums(num1, setN.at(nums.at(3)), expre.at(2));
         callFunction(num1);
         
         num1 = joinNums(setN.at(nums.at(1)), setN.at(nums.at(2)), expre.at(1));
         num1 = joinNums(num1, setN.at(nums.at(3)), expre.at(2));
         num1 = joinNums(setN.at(nums.at(0)), num1, expre.at(0));
         callFunction(num1);
         
         num1 = joinNums(setN.at(nums.at(2)), setN.at(nums.at(3)), expre.at(2));
         num1 = joinNums(setN.at(nums.at(1)), num1, expre.at(1));
         num1 = joinNums(setN.at(nums.at(0)), num1, expre.at(0));
         callFunction(num1);
         
         
         num1 = joinNums(setN.at(nums.at(0)), setN.at(nums.at(1)), expre.at(0));
  double num2 = joinNums(setN.at(nums.at(2)), setN.at(nums.at(3)), expre.at(2));
         num1 = joinNums(num1, num2, expre.at(1));
}

void stackefy(vector<double> &expre, vector<ll> &nums)
{
  if(expre.size() >= 3)
  {
    /*for(int i = 0; i < expre.size(); i++)
    {
      cout << expre.at(i) << " ";
    }
    cout << endl;*/
    casses(expre, nums);
    return;
  }
  for(ll i = 0; i < 4; i++)
  {
    expre.push_back(i);
    stackefy(expre, nums);
    expre.pop_back();
  }
}

//prev = -1 when start
void pick(vector<ll> &nums)
{
  if(nums.size() >= 4)
  {
    vector<double> expr;
    stackefy(expr, nums);
    return;
  }
  for(ll i = 0; i < 4; i++)
  {
    bool continueNow = false;
    for(ll j = 0; j < nums.size(); j++)
    {
      if(nums.at(j) == i)
      {
        continueNow = true;
        break;
      }
    }
    if(continueNow)
      continue;
    nums.push_back(i);
    pick(nums);
    nums.pop_back();
  }
}


void getNums(vector<ll> &nums, ll pos)
{
  if(nums.size() >= 4)
  {
    setN.clear();
    valid.clear();
    valid.resize(10000, false);
    setN.push_back(nums.at(0));
    setN.push_back(nums.at(1));
    setN.push_back(nums.at(2));
    setN.push_back(nums.at(3));
    vector<ll> nums2;
    pick(nums2);
    
    ll max = 0;
    for(; true; max++)
    {
      if(!valid.at(max))
      {
        break;
      }
    }
    
    if(max > largest)
    {
      largest = max;
      solution = 0;
      for(int i = 0; i < setN.size(); i++)
      {
        solution *= 10;
        solution += setN.at(i);
      }
    } 
    
    
    return;
  }
  for(ll i = pos + 1; i < 10; i++)
  {
    nums.push_back(i);
    getNums(nums, i);
    nums.pop_back();
  }
}





int main()
{
  valid.resize(10000, false);
  vector<ll> nums;
  ll start = 0;

  
  getNums(nums, start);

  cout << solution << endl;
  cout << largest << endl;
  
  
  
  return 0;
}




