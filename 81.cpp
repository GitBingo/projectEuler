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
      smallest[i][j] = 999999999;
    }
  }
  for(ll counter = size - 1; counter >= 0; counter--)
  {
    for(ll counter2 = 0; counter2 <= counter; counter2++)
    {
      ll i = size - counter - 1;
      ll j = counter2 + i;
      if(i == 0 && j == 0)
      {
        smallest[i][j] = data[i][j];
        continue;
      }
      if(i == 0)
      {
        smallest[i][j] = data[i][j] + smallest[i][j - 1];
        smallest[j][i] = data[j][i] + smallest[j - 1][i];
        continue;
      }
      smallest[i][j] = min(data[i][j] + smallest[i][j-1], data[i][j] + smallest[i - 1][j]);
      smallest[j][i] = min(data[j][i] + smallest[j][i-1], data[j][i] + smallest[j - 1][i]);
    }
  }
  /*for(ll i = 0; i < size; i++)
  {
    for(ll j = 0; j < size; j++)
    {
      cout << smallest[i][j] << " ";
    }
    cout << endl;
  }*/
  cout << smallest[size - 1][size - 1] << endl;
  return 0;
}




