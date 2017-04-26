#include <bits/stdc++.h>
#include "InfInt.h"


using namespace std;

typedef InfInt ll;



bool reorder(ll num1, ll num2)
{
	vector<ll> digits(10, 0);
	for(int i = 0; num1 > 0; i++)
	{
		ll holder = num1%10;
		digits[holder.toInt()]++;
		num1/=10;
	}
	for(int i = 0; num2 > 0; i++)
	{
		ll holder = num2%10;
		digits[holder.toInt()]--;
		num2/=10;
	}
	for(int i = 0; i < digits.size(); i++)
	{
		if(digits.at(i) != 0)
		{
			return false;
		}
	}
	return true;
}



int main()
{
	
	for(int digitSize = 1; true; digitSize++)
	{
		cout << digitSize << endl;
		vector<ll> nums;
		
		for(ll i = 1; (i * i * i).numberOfDigits() <= digitSize; i++)
		{
			//cout << "here" << endl; 
			if((i * i * i).numberOfDigits() == digitSize)
			{
				nums.push_back(i * i * i);
			}
		}
		cout << nums.size() << endl;
		for(int i = 0; i < nums.size(); i++)
		{
			for(int j = i + 1; j < nums.size(); j++)
			{
				if(!reorder(nums.at(i), nums.at(j)))
					continue;
				for(int k = j + 1; k < nums.size(); k++)
				{
					if(!reorder(nums.at(i), nums.at(k)))
						continue;
					for(int l = k + 1; l < nums.size(); l++)
					{
						if(!reorder(nums.at(i), nums.at(l)))
							continue;
						for(int m = l + 1; m < nums.size(); m++)
						{
							if(!reorder(nums.at(i), nums.at(m)))
								continue;
							cout << nums.at(i) << " " << nums.at(j) << " " << nums.at(k) << " " << nums.at(l) << " " << nums.at(m) << endl;
						}
					}
				}
			}
		}
		cout << endl;
		//ll temp;
		//cin >> temp;
	}
	
	
  return 0;
}




