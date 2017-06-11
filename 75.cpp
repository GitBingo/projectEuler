#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

using namespace std;


typedef unsigned long long ll;


ll gcd(ll n, ll m)
{
	if(m == 0)
		return n;
	return gcd(m, n %m);
}

int main()
{
    vector<ll> data(3000000,0);
    cout << data.size() << endl;
    ll sum = 0;
    for(int m = 2; m < 1225; m++)
    {
        for(int n = 1; n < m; n++)
        {
            if((m % 2 == 1 && n % 2 == 1) || (gcd(m,n) != 1))
                continue;
            ll loc = 2*m*m+2*m*n;
            ll loc2 = loc;
            while(loc2 <= 1500000)
            {
                data.at(loc2)++;
                loc2+=loc;
            }
        }
    }
    for(int i = 1; i <= 1500000; i++)
    {
        if(data.at(i) == 1)
        {
            sum++;
        }
    }
    cout << sum << endl;
	return 0;
}

















