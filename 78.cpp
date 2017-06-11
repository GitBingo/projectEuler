#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
#include <map>
#include "InfInt.h"

using namespace std;


typedef long long ll;


struct partitionFunction
{
    map<ll, ll> remember;
    
    ll getPartitionsModM(ll n, ll m)
    {
        if(n < 0)
            return 0;
        if(n == 0)
            return 1;
        if(remember.find(n) != remember.end())
            return remember[n];
        ll sum = 0;
        ll val = 1;
        for(ll i = 1;  val <= n; i++)
        {
            ll multiply = 1;
            if(i % 2 == 0)
                multiply = -1;
            ll three = 3;
            val = ((three*i*i) + i) / 2;
            sum += getPartitionsModM(n - val, m) * multiply;
            val = ((three*i*i) - i) / 2;
            sum += getPartitionsModM(n - val, m) * multiply;
        }
        remember[n] = sum % m;
        return sum % m;
    }
};

int main()
{
    partitionFunction theData;
    
    for(int i = 1; i < 10000000; i++)
    {
        ll num = theData.getPartitionsModM(i, 1000000000);
        //cout << i << " " << num << endl;
        if(i % 1000 == 0)
        {
            cout << i << endl;
        }
        if(num % 1000000 == 0)
        {
            cout << "Here!!!!!!!!!!!!!!!!            " << i << endl;
        }
    }
    
    //cout << "Sol " << theData.getPartitions(200) << endl;
	return 0;
}

















