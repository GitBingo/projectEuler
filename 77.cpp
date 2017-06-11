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

ll answer;

ll theNum;

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

void val(ll last, ll sum)
{
    //cout << sum << endl;
    //ll temp;
    //cin >> temp;
    if(sum == theNum)
    {
        answer++;
        return;
    }
    if(sum > theNum)
    {
        return;
    }
    for(int i = last; i + sum <= theNum; i++)
    {
        if(i != theNum && isPrime(i))
        { 
            val(i, sum + i);
        }
    }
}

int main()
{
    answer = 0;
    theNum = 5;
    cin >> theNum;
    val(1, 0);
    cout << answer << endl;
	return 0;
}

















