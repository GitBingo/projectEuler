#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	
	ll x, y;
	ll i = 0;
	double max = 0;
	ll sol = -1;
	//Read in the numbers, convert everything to base 10
	//And look for the highest power
	while(cin >> x >> y)
	{
		i++;
		double val = log10(x);
		y *= val;
		if(y >= max)
		{
			max = y;
			sol = i;
		}
	}
	cout << sol << endl;
  
  return 0;
}




