#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;


ll charVal(char c)
{
  if(c == 'I')
    return 1;
  if(c == 'V')
    return 5;
  if(c == 'X')
    return 10;
  if(c == 'L')
    return 50;
  if(c == 'C')
    return 100;
  if(c == 'D')
    return 500;
  if(c == 'M')
    return 1000;
  return 0;
}

ll getVal(string s)
{
  ll total = 0;
  string s2;
  for(int i = 0; i < s.size(); i++)
  {
    if(i + 1 < s.size() && s.at(i) == 'I' && s.at(i + 1) == 'V')
    {
      total += 4;
      i++;
    }else
    if(i + 1 < s.size() && s.at(i) == 'I' && s.at(i + 1) == 'X')
    {
      total += 9;
      i++;
    }else
    if(i + 1 < s.size() && s.at(i) == 'X' && s.at(i + 1) == 'L')
    {
      total += 40;
      i++;
    }else
    if(i + 1 < s.size() && s.at(i) == 'X' && s.at(i + 1) == 'C')
    {
      total += 90;
      i++;
    }else
    if(i + 1 < s.size() && s.at(i) == 'C' && s.at(i + 1) == 'D')
    {
      total += 400;
      i++;
    }else
    if(i + 1 < s.size() && s.at(i) == 'C' && s.at(i + 1) == 'M')
    {
      total += 900;
      i++;
    }else
    {
      total += charVal(s.at(i));
    }
  }
  return total;
}

string shortStr(ll num)
{
  string s;
  while(num >= 1000)
  {
    s += 'M';
    num -= 1000;
  }
  
  if(num >= 900)
  {
    s += 'C';
    s += 'M';
    num -= 900;
  }
  if(num >= 500)
  {
   s += 'D';
   num -= 500; 
  }
  if(num >= 400)
  {
    s += 'C';
    s += 'D';
    num -= 400;
  }
  while(num >= 100)
  {
    s += 'C';
    num -= 100;
  }
  
  
  if(num >= 90)
  {
    s += 'X';
    s += 'C';
    num -= 90;
  }
  if(num >= 50)
  {
   s += 'L';
   num -= 50; 
  }
  if(num >= 40)
  {
    s += 'X';
    s += 'L';
    num -= 40;
  }
  while(num >= 10)
  {
    s += 'X';
    num -= 10;
  }
  
  
  if(num >= 9)
  {
    s += 'I';
    s += 'X';
    num -= 9;
  }
  if(num >= 5)
  {
   s += 'V';
   num -= 5; 
  }
  if(num >= 4)
  {
    s += 'I';
    s += 'V';
    num -= 4;
  }
  while(num >= 1)
  {
    s += 'I';
    num -= 1;
  }
  return s;
}

int main()
{
  string s;
  ll sol = 0;
  while(cin >> s)
  {
    ll length = s.size();
    
    sol += length - shortStr(getVal(s)).size(); 
  }
  cout << sol << endl;
  return 0;
}




