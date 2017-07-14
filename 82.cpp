#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll size;

int main()
{
  size = 80;
  ll data[size][size];
  ll smallest[size][size];
  for(ll i = 0; i < size; i++)
  {
    for(ll j = 0; j < size; j++)
    {
      cin >> data[i][j];
    }
  }
  
  
  ll solution = 999999999;
  
  for(ll k = 0; k < size; k++)
  {
    for(ll i = 0; i < size; i++)
    {
      for(ll j = 0; j < size; j++)
      {
        smallest[i][j] = 999999999;
      }
    }
    
    smallest[k][0] = data[k][0];
    
    for(ll i = 0; i < k; i++)
    {
      smallest[k - i - 1][0] = smallest[k - i][0] + data[k - i - 1][0];
    }
    for(ll i = k + 1; i < size; i++)
    {
      smallest[i][0] = smallest[i - 1][0] + data[i][0];
    }
    
    /*for(ll i = 0; i < size - 1; i++)
    {
      for(ll j = 0; j < size; j++)
      {
        swap(data[i][j], data[i + 1][j]);
      }
    }*/
    
    //trigle changes up
    for(int l = 0; l < size + 1; l++)
    {
      for(ll j = 0; j < size; j++)
      {
        for(ll i = 0; i < size; i++)
        {
          if(i + 1 < size)
            smallest[i + 1][j] = min(smallest[i + 1][j], smallest[i][j] + data[i + 1][j]);
          if(j + 1 < size)
            smallest[i][j + 1] = min(smallest[i][j + 1], smallest[i][j] + data[i][j + 1]);
          if(i - 1 >= 0)
            smallest[i - 1][j] = min(smallest[i - 1][j], smallest[i][j] + data[i - 1][j]);
        }
      }
    }
    
    
    for(ll i = 0; i < size; i++)
    {
      if(smallest[i][size - 1] < solution)
      {
        solution = smallest[i][size - 1];
      }
    }
    /*for(ll i = 0; i < size; i++)
    {
      for(ll j = 0; j < size; j++)
      {
        cout << smallest[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl << endl;*/
  }
  cout << solution << endl;
  //cout << smallest[size - 1][size - 1] << endl;
  return 0;
}




