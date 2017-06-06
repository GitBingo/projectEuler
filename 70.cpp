#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;


typedef long long ll;


ll lowestPrime(ll n)
{
    ll sqrtN = sqrt(n);
    for(int i = 2; i <= sqrtN; i++)
    {
        if(n % i == 0)
        {
            return i;
        }
    }
    
    return n;
}


ll totient(ll n)
{
    ll sol = 1;
    while(n > 1)
    {
        ll prime = lowestPrime(n);
        ll powN = 0;
        while(n % prime == 0)
        {
            n /= prime;
            powN++;
        }
        sol *= pow(prime, powN) - pow(prime, powN - 1);
    }
    return sol;
}

bool sameButReordered(ll n1, ll n2)
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
    ll top = 100000000;
    ll bottom = 1;	
	for(int i = 2; i <= 10000000; i++)
	{
	    if(i % 1000000)
	    ll theTot = totient(i);
	    if(sameButReordered(i, theTot))
	    {
	        if(i/(double)theTot < top / (double)bottom)
	        {
	            top = i;
	            bottom = theTot;
	        }
	    }
	}
	cout << top << endl;
	return 0;
}

















