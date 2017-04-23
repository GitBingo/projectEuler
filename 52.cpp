#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool same(ll n1, ll n2)
{
	vector<ll> num1;
	vector<ll> num2;
	while(n1 > 0)
	{
		num1.push_back(n1 % 10);
		n1 /= 10;
	}
	while(n2 > 0)
	{
		num2.push_back(n2 % 10);
		n2 /= 10;
	}
	sort(num1.begin(), num1.end());
	sort(num2.begin(), num2.end());
	if(num1.size() != num2.size())
	{
		return false;
	}
	for(int i = 0; i < num1.size(); i++)
	{
		if(num1.at(i) != num2.at(i))
		{
			return false;
		}
	}
	return true;
}


int main()
{
	
	for(int i = 1; true; i++)
	{
		if(same(i, 2*i) && 
			same(i, 3*i) && 
			same(i, 4*i) && 
			same(i, 5*i) && 
			same(i, 6*i) )
			{
				cout << i << endl;
				break;
			}
	}
  
  
  //cout << maxNum(56003) << endl;
  return 0;
}
