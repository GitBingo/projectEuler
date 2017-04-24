#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//bool isPrimeT[1000000];

vector <bool> isPrimeT;

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


bool validSet(vector<ll> &nums)
{
	for(int i = 0; i < nums.size(); i++)
	{
		for(int j = i + 1; j < nums.size(); j++)
		{
			ll val1 = nums.at(i) * pow(10, ceil(log10(nums.at(j)))) + nums.at(j);
			ll val2 = nums.at(j) * pow(10, ceil(log10(nums.at(i)))) + nums.at(i);
			//cout << val1 << " " << val2 << endl;
			if(!isPrimeT[val1] || !isPrimeT[val1])
			{
				return false;
			}
		}
	}
	return true;
}



int main()
{
	vector<ll> primes;
	for(int i = 2; i < 1000000; i++)
	{
		bool theFind = isPrime(i);
		isPrimeT.push_back(theFind);
		if(theFind)
		{
			//cout << i << endl;
			//cout << primes.size() << endl;
			primes.push_back(i);
		}
	}
	
	cout << "starting" << endl;
	cout << primes.size() << " : " << primes.at(200) << endl;
	cout << primes.at(1) << endl;
	//for(int i = 1; i < 300; i++)
	//{
		//cout << i << endl;
		//80 * 1,600,000,000
		for(int j = 0; j < 200; j++)
		{
			for(int k = j + 1; k < 200; k++)
			{
				for(int l = k + 1; l < 200; l++)
				{
					for(int m = l + 1; m < 200; m++)
					{
						vector<ll> test;
						//test.push_back(primes.at(i));
						test.push_back(primes.at(j));
						test.push_back(primes.at(k));
						test.push_back(primes.at(l));
						test.push_back(primes.at(m));
						if(validSet(test))
						{
							cout << " " << primes.at(j) << " " << primes.at(k) << " " << primes.at(l) << " " << primes.at(m) << endl;
						}
					}
				}
			}
		//}
	}
	
	
  return 0;
}




