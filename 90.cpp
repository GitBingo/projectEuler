#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll total;

bool singleNum(ll num, vector<bool> &first, vector<bool> &second)
{
  if((first.at(num / 10) && second.at(num % 10)) || 
     (first.at(num % 10) && second.at(num / 10)))
     {
      return true;
     }
  return false;
}

bool valid(vector<bool> &first, vector<bool> &second)
{
  if(singleNum(9, first, second) || singleNum(6, first, second))
  {
    if(singleNum(1, first, second))
    {
      if(singleNum(4, first, second))
      {
        if(singleNum(16, first, second) || singleNum(19, first, second))
        {
          if(singleNum(25, first, second))
          {
            if(singleNum(36, first, second) || singleNum(39, first, second))
            {
              if(singleNum(49, first, second) || singleNum(46, first, second))
              {
                if(singleNum(94, first, second) || singleNum(64, first, second))
                {
                  if(singleNum(81, first, second))
                  {
                    return true;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return false;
}

void pick2(ll pos, ll used, vector<bool> &picking, vector<bool> &old)
{
  
  if(used >= 6)
  {
    //cout << total << endl;
    if(valid(picking, old))
    {
      total++;
    }
    return;
  }
  
  if(pos >= 10)
  {
    return;
  }
  for(int i = pos; i < picking.size(); i++)
  {
    if(!picking.at(i))
    {
      picking.at(i) = true;
      pick2(i + 1, used + 1, picking, old);
      picking.at(i) = false;
    }
  }
}



void pick(ll pos, ll used, vector<bool> &picking)
{
  
  if(used >= 6)
  {
    /*for(int i = 0; i < picking.size(); i++)
    {
      if(picking.at(i))
      {
        cout << "X";
      }else
      {
        cout << "O";
      }
    }
    cout << endl;
    */
    vector<bool> used(10, false);
    pick2(0,0, used, picking);
    return;
  }
  
  if(pos >= 10)
  {
    return;
  }
  for(int i = pos; i < picking.size(); i++)
  {
    if(!picking.at(i))
    {
      picking.at(i) = true;
      pick(i + 1, used + 1, picking);
      picking.at(i) = false;
    }
  }
}


int main()
{
  total = 0;
  vector<bool> used(10, false);
  pick(0,0, used);
  cout << total / 2 << endl;
  return 0;
}




