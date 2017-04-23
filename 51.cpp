#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


bool isPrime(ll num)
{
  if(num < 2)
  {
    return false;
  }
  ll sqrtN = sqrt(num) + 1;
  if(num % 2 == 0 && num != 2)
  {
    return false;
  }
  for(int i = 3; i <= sqrtN; i+=2)
  {
    if(num % i == 0)
    {
      return false;
    }
  }
  return true;
}

ll goodPrimes;




void replaceDigit(vector<ll> &num, vector<bool> &visited, ll replace, ll valReplace,
											ll prev)
{
	if(replace == 0)
	{
		ll tempSol = 0;
		for(int j = 0; j < 10; j++)
		{
			if(j == 0 && visited.at(0))
			{
				continue;
			}
			ll sol = 0;
			for(int i = 0; i < num.size(); i++)
			{
				sol *= 10;
				if(num.at(i) == 11)
				{
					sol += j;
				}else
				{
					sol += num.at(i);
				}
			}
			if(isPrime(sol))
			{
				tempSol++;
			}
		}
		if(goodPrimes < tempSol)
		{
			if(tempSol == 8)
			{
				for(int j = 0; j < 10; j++)
				{
					if(j == 0 && visited.at(0))
					{
						continue;
					}
					ll sol = 0;
					for(int i = 0; i < num.size(); i++)
					{
						sol *= 10;
						if(num.at(i) == 11)
						{
							sol += j;
						}else
						{
							sol += num.at(i);
						}
					}
					if(isPrime(sol))
					{
						cout << "Here " << sol << endl;
					}
				}
			}
			goodPrimes = tempSol;
		}
		
		
		
		//cout << sol << endl;
		return;
	}
	
	for(int i = prev; i < num.size(); i++)
	{
		if(!visited.at(i))
		{
			visited.at(i) = true;
			ll temp = num.at(i);
			num.at(i) = valReplace;
			replaceDigit(num, visited, replace - 1, valReplace, i);
			visited.at(i) = false;
			num.at(i) = temp;
		}
	}
}


ll maxNum(ll num)
{
	ll temp = num;
	vector<ll> numbers;
	goodPrimes = 0;
	while(temp > 0)
	{
		numbers.push_back(temp % 10);
		temp /= 10;
	}
	reverse(numbers.begin(), numbers.end());
	vector<bool> visited(numbers.size(), false);
	
	/*
	*/
	for(int i = 1; i <= numbers.size(); i++)
	{
		replaceDigit(numbers, visited, i, 11, 0);
		//cout << i << " " << goodPrimes << endl;
	}
	return goodPrimes;
}
//*2*3*3
//3+2*1^2
//3 2*7, 5 2*6, 7 2*5, 11 2*3, 13 2*2, 17
int main()
{
  /*for(ll num = 1; true; num++)
  {
  	
  }*/
  
  /*vector<ll> num;
  goodPrimes = 0;
  vector<bool> visited(5, false);
  num.push_back(5);
  num.push_back(6);
  num.push_back(0);
  num.push_back(0);
  num.push_back(3);
  replaceDigit(num, visited, 2, 11, 0);*/
  
  for(ll i = 2; true; i++)
  {
  	//cout << i << endl;
  	if(isPrime(i) && maxNum(i) == 8)
  	{
  		cout << i << endl;
  		break;
  	}
  }
  
  //cout << maxNum(56003) << endl;
  return 0;
}
