#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct nChooseR{

	ll table[1000][1000];

	nChooseR() {
		for(ll i = 0; i < 1000; i++)
		{
			for(ll j = 0; j < 1000; j++)
			{
				table[i][j] = -1;
			}
		}
	}

	ll querry(ll n, ll r)
	{
		if(table[n][r] != -1)
		{
			return table[n][r];
		}
		
		if(n == r)
		{
			return 1;
		}
		if(r == 0)
		{
			return 1;
		}
		ll val = querry(n - 1, r - 1) + querry(n - 1, r);
		table[n][r] = val;
		return val;
	}
	
};

int main()
{
	//nChooseR getData;
	//cout << getData.querryModM(1, 0, 10000000) << endl;
	ll total = 0;
	nChooseR getData;
  for(int i = 1; i <= 100; i++)
  {
  	for(int j = 1; j <= i; j++)
  	{
  		//cout << getData.querryModM(i, j, 1100000) << endl;
  		if(getData.querryModM(i, j, 1100000) > 1000000)
  		{
  			//cout << getData.querryModM(i, j, 1000000000) << endl;
  			total++;
  		}
  	}
  }
  cout << total << endl;
  
  //cout << maxNum(56003) << endl;
  return 0;
}





