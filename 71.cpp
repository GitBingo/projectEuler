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
    ll top = 2;
    ll bottom = 5;
    
    for(int i = 9; i < 1000000; i++)
    {
        ll start = ceil((top * i) / (double)bottom);
        while(start / (double)i < 3.0/7.0)
        {
            
            if(gcd(start, i) == 1)
            {
                top = start;
                bottom = i;
            }
            start++;
        }
    }
    cout << top <<"/" << bottom << endl;
    
	return 0;
}

















