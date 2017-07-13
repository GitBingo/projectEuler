#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;


ll theFirst;

//start is a two digit number of the four digit
void pickOctagonal(ll start, vector<ll> &fill)
{
 
  ll prev = 1;
  for(int i = 1; prev <= 9999; i++)
  {
    prev = (i *(3*i -2));
    if(prev < 1000)
      continue;
    if(prev / 100 == start)
    {
      //cout << prev << endl;
      fill.push_back(prev);
    }
  }
}


//start is a two digit number of the four digit
void pickHeptagonal(ll start, vector<ll> &fill)
{
  ll prev = 1;
  for(int i = 1; prev <= 9999; i++)
  {
    prev = (i *(5*i - 3)) / 2;
    if(prev < 1000)
      continue;
    if(prev / 100 == start)
    {
      //cout << prev << endl;
      fill.push_back(prev);
    }
  }
}

//start is a two digit number of the four digit
void pickHexagonal(ll start, vector<ll> &fill)
{
  ll prev = 1;
  for(int i = 1; prev <= 9999; i++)
  {
    prev = (i *(2*i - 1));
    if(prev < 1000)
      continue;
    if(prev / 100 == start)
    {
      //cout << prev << endl;
      fill.push_back(prev);
    }
  }
}

//start is a two digit number of the four digit
void pickSquare(ll start, vector<ll> &fill)
{
  ll prev = 1;
  for(int i = 1; prev <= 9999; i++)
  {
    prev = (i *(i));
    if(prev < 1000)
      continue;
    if(prev / 100 == start)
    {
      //cout << prev << endl;
      fill.push_back(prev);
    }
  }
}


//start is a two digit number of the four digit
void pickPentagonal(ll start, vector<ll> &fill)
{
  ll prev = 1;
  for(int i = 1; prev <= 9999; i++)
  {
    prev = (i *(3 * i - 1)) / 2;
    if(prev < 1000)
      continue;
    if(prev / 100 == start)
    {
      //cout << prev << endl;
      fill.push_back(prev);
    }
  }
}




//start is a two digit number of the four digit
void pickTriangle(ll start, vector<ll> &fill)
{
  ll prev = 1;
  for(int i = 1; prev <= 9999; i++)
  {
    prev = (i *(i + 1)) / 2;
    if(prev < 1000)
      continue;
    if(prev / 100 == start)
    {
      //cout << prev << endl;
      fill.push_back(prev);
    }
  }
}

void searchCase(int i, vector<ll> &fill, ll start)
{
  if(i == 0)
  {
    pickTriangle(start, fill);
  }
  if(i == 1)
  {
    pickSquare(start, fill);
  }
  if(i == 2)
  {
    pickPentagonal(start, fill);
  }
  if(i == 3)
  {
    pickHexagonal(start, fill);
  }
  if(i == 4)
  {
    pickHeptagonal(start, fill);
  }
  if(i == 5)
  {
    pickOctagonal(start, fill);
  }
}

void pickOrder(vector<bool> &visited, ll start, string sol, ll ans)
{
  bool empty = true;
  
  for(int i = 0; i < visited.size(); i++)
  {
    if(!visited.at(i))
    {
      empty = false;
      visited.at(i) = true;
      
      vector<ll> fill;
      searchCase(i, fill, start);
      
      for(int j = 0; j < fill.size(); j++)
      {
         pickOrder(visited, fill.at(j) % 100, 
         sol + " " + to_string(fill.at(j))+":"+to_string(i)+":", ans + fill.at(j));
      }
      
      visited.at(i) = false;
    }
  }
  //cout << sol << endl;
  if(empty && start == theFirst)
  {
    cout << sol << " Answer :" << ans << endl;
  }
}


int main()
{
	for(int i = 10; i < 100; i++)
  {
    theFirst = i;
    vector<bool> visited(6, false);
    pickOrder(visited, i, "", 0);
  }
	
  return 0;
}




