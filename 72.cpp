#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;


typedef long long ll;


ll gcd(ll n, ll m)
{
	if(m == 0)
		return n;
	return gcd(m, n %m);
}

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

int main()
{
   
    ll sol = 0;
    for(int i = 2; i <= 1000000; i++)
    {
        sol += totient(i);
    }
    cout << sol << endl;
    
	return 0;
}

















