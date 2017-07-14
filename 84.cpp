#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int roll()
{
  return rand() % 4 + 1;
}

ll topVal(vector<ll> &landed)
{
  ll loc = 0;
  ll val = landed.at(0);
  for(int i = 0; i < landed.size(); i++)
  {
    if(landed.at(i) > val)
    {
      val = landed.at(i);
      loc = i;
    }
  }
  return loc;
}

ll CuminityChest(ll loc)
{
  ll cards[2] = {0, 10};
  ll roll = rand() % 16;
  if(roll > 1)
  {
    return loc;
  }
  return cards[roll];
}

ll Chance(ll loc)
{
  ll cards[6] = {0, 10, 11, 24, 39, 5};
  ll roll = rand() % 16;
  if(roll <= 5)
  {
    return cards[roll];
  }
  if(roll == 6 || roll == 7)
  {
    while(loc % 10 != 5)
    {
      loc++;
    }
    return loc % 40;
  }
  if(roll == 8)
  {
    while(loc != 12 && loc != 28)
    {
      loc++;
      loc = loc % 40;
    }
    return loc;
  }
  if(roll == 9)
  {
    return (loc + 37) % 40;
  }
  
  return loc;
}

int main()
{
  srand(56);
  ll bored[40] = {0,0,1,0,0,0,0,2,0,0,
                  0,0,0,0,0,0,0,1,0,0,
                  0,0,2,0,0,0,0,0,0,0,
                  3,0,0,1,0,0,2,0,0,0};
  ll loc = 0;
  vector<ll> landedArea(40, 0);
  ll max = 100000000;
  ll doubleRolled = 0;
  for(ll i = 0; i < max; i++)
  {
    landedArea[loc]++;
    ll roll1 = roll();
    ll roll2 = roll();
    //cout << loc << " " << roll1 << " " << roll2 << " " 
      //                  << bored[loc + roll1 + roll2] << endl;
    if(roll1 == roll2)
    {
      doubleRolled++;
    }else
    {
      doubleRolled = 0;
    }
    
    if(doubleRolled == 3)
    {
      doubleRolled = 0;
      loc = 10;
      continue;
    }
    loc += roll1 + roll2;
    loc %= 40;
    if(bored[loc] == 1)
    {
      loc = CuminityChest(loc);
    }else if(bored[loc] == 2)
    {
      loc = Chance(loc);
    }else if(bored[loc] == 3)
    {
      loc = 10;
    }
  }
  for(int i = 0; i < 4; i++)
  {
    ll location = topVal(landedArea);
    cout << location << " " << landedArea.at(location) / (double)max << endl;
    landedArea.at(location) = 0;
  }
  //cout << landedArea[24] / (double)max << endl;
  return 0;
}




