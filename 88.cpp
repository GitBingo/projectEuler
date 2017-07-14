#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll countOfTotal;
ll maxN;
std::unordered_map<std::string,bool> mymap;

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

void buildVectorPrimes(ll n, vector<ll> &primes)
{
  while(n > 1)
  {
    ll prime = lowestPrime(n);
    n /= prime;
    primes.push_back(prime);
  }
}

vector<ll> lengths;

void recuseSet(ll n, vector<ll> &primes)
{
  ll sum = 0;
  if(primes.size() > 1)
  {
    sort( primes.begin(), primes.end() );
    
    string check;
    for(int i = 0; i < primes.size(); i++)
    {
      check += " ";
      check += to_string(primes.at(i));
    }
    
    if(mymap.find(check) != mymap.end())
    {
      return;
    }
    mymap[check] = true;
  }
  /*for(int i = 0; i < primes.size(); i++)
  {
    cout << primes.at(i) << " ";
  }
  cout << endl;*/
  for(int i = 0; i < primes.size(); i++)
  {
    sum += primes.at(i);
  }
  if(n >= sum)
  {
    ll length = n - sum + primes.size();
    if(length <= maxN && lengths.at(length) == -1)
    {
      lengths.at(length) = n;
      countOfTotal++;
    }
  }
  for(int k = 0; k < primes.size(); k++)
  {
    vector<ll> temp;
    for(int i = 0; i < primes.size(); i++)
    {
      if(i != k)
      {
        temp.push_back(primes.at(i));
      }
    }
    for(int i = 0; i < temp.size(); i++)
    {
      temp.clear();
      for(int i = 0; i < primes.size(); i++)
      {
        if(i != k)
        {
          temp.push_back(primes.at(i));
        }
      }
      temp.at(i) *= primes.at(k);
      recuseSet(n, temp);
      
    }
  }
}

void tryNumber(ll n)
{
  vector<ll> primes;
  buildVectorPrimes(n, primes);
  recuseSet(n, primes);
}

int main()
{
  countOfTotal = 0;
  maxN = 12000;
  lengths.resize(maxN + 1, -1);
  for(int i = 1; countOfTotal < maxN; i++)
  {
    cout << i << " " << countOfTotal << endl;
    tryNumber(i);
    //cout << endl << endl;
  }
  
  /*for(int i = 0; i < lengths.size(); i++)
  {
    cout << i << " " << lengths.at(i) << endl;
  }*/
  
  sort( lengths.begin(), lengths.end() );
  lengths.erase( unique(lengths.begin(), lengths.end()), lengths.end());
  ll solution = 0;
  for( int i = 0; i < lengths.size(); i++)
  {
    if(lengths.at(i) != -1)
    {
      solution += lengths.at(i);
    }
  }
  cout << solution - 1 << endl;
  return 0;
}




