#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool loopTriangle(ll num)
{
	ll curr = 0;
	for(ll i = 1; curr <= num; i++)
	{
		curr = (i*(i + 1)) / 2;
		if(num == curr)
		{
			return true;
		}
	}
	return false;
}


bool loopHexagonal(ll num)
{
	ll curr = 0;
	for(ll i = 1; curr <= num; i++)
	{
		curr = (i*(2*i - 1));
		if(num == curr)
		{
			return true;
		}
	}
	return false;
}


bool loopPentagonal()
{
	ll curr = 0;
	for(ll i = 1; true; i++)
	{
		curr = (i*(3*i - 1)) / 2;
		if(loopHexagonal(curr) && loopTriangle(curr))
		{
			cout << curr << endl;
		}
	}
	return false;
}



int main()
{
  
  loopPentagonal();
   
  return 0;
}
