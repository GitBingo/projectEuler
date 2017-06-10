#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;


typedef unsigned long long ll;


unordered_map<ll, ll> visited;

ll fac(ll n)
{
    ll answer = 1;
    for(int i = 2; i<= n; i++)
    {
        answer *= i;
    }
    return answer;
}

ll cycle(ll n)
{
    visited.clear();
    ll sol = 0;
	while(visited.find(n) == visited.end())
	{
	    sol++;
	    visited[n] = 1;
	    ll m = 0;
	    while(n > 0)
	    {
	        m += fac(n % 10);
	        n /= 10;
	    }
	    n = m;
	}
	return sol;
}

int main()
{
    cout << cycle(69) << endl;
    ll sum = 0;
    for(int i = 2; i <= 1000000; i++)
    {
        if(i % 10000 == 0)
        {
            cout << i << endl;
        }
        if(cycle(i) == 60)
        {
            sum++;
        }
    }
    cout << sum << endl;
	return 0;
}

















