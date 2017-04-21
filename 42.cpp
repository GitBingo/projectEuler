#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isTriangle(ll num)
{
  ll sum = 0;
  for(ll i = 0; sum <= num; i++)
  {
    //cout << sum << " " << num << endl;
    if(sum == num)
    {
      //cout << "Ran" << endl;
      return true;
    }
    sum += i;
  }
  return false;  
}

ll convert(string s)
{
  ll total = 0;
  for(int i = 0; i < s.size(); i++)
  {
    total += (s.at(i) - 'A') + 1;
  }
  return total;
}

int main()
{
  //cout << convert("SKY") << endl;
  //cout << isTriangle(convert("SKY")) << endl;
  ifstream fin("p042_words.txt");
  ll ans = 0;
  string s;
  while(fin >> s)
  {
    //cout << isTriangle(convert(s)) << endl;
    if(isTriangle(convert(s)))
    {
      ans++;
    }
  }
  cout << ans << endl;
  fin.close();
  return 0;
}







