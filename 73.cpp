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

int main()
{
    ll top = 1;
    ll bottom = 3;
    
    ll total = 0;
    
    for(int i = 2; i <= 12000; i++)
    {
        ll start = ceil((top * i) / (double)bottom);
        while(start / (double)i < 1.0/2.0)
        {
            
            if(gcd(start, i) == 1)
            {
                total++;
            }
            start++;
        }
    }
    total--;
    cout << total << endl;
    
	return 0;
}

















