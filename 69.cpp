#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

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

int main()
{
	cout << totient(9) << endl;
	ll sol = 0;
	ll toSol = 1;
	for(int i = 2; i <= 1000000; i++)
	{
	    if(sol/(double)toSol < i/(double)totient(i))
	    {
	        sol = i;
	        toSol = totient(i);
	    }
	}
	cout << sol << endl;
	return 0;
}

















