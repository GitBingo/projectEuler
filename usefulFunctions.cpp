#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

//Given a matrix compute the row reduce ecelont form
void RowReduce(ll nrows, ll ncols)
{

    ll lead = 0; 

    while (lead < nrows) {
        double d, m;

        for (ll r = 0; r < nrows; r++) { 
            d = matrix[lead][lead];
            m = matrix[r][lead] / matrix[lead][lead];

            for (ll c = 0; c < ncols; c++) { 
                if (r == lead)
                    matrix[r][c] /= d;               
                else
                    matrix[r][c] -= matrix[lead][c] * m; 
            }
        }

        lead++;
    }
}

ll gcd(ll n, ll m)
{
	if(m == 0)
		return n;
	return gcd(m, n %m);
}

ll continuedFraction(ll num)
{
  ll intPart = sqrt(num);
  
  ll underSqrt = num;
  ll frontSqrt = 1;
  ll added = -1 * intPart;
  ll underFrac = 1;
  
  while(true)
  { 
 		
 		cout << intPart << endl;
 		
  	//Flipping fraction
  	ll tempFrontSqrt = underFrac * frontSqrt;
  	ll tempAdded = -1 * underFrac * added;
  	ll tempUnderFrac = underSqrt - added * added;
  	ll commenFactor = gcd(gcd(abs(tempFrontSqrt), abs(tempAdded)), abs(tempUnderFrac));
  	tempFrontSqrt /= commenFactor;
  	tempAdded /= commenFactor;
  	tempUnderFrac /= commenFactor;
  	
  	frontSqrt = tempFrontSqrt;
  	added = tempAdded;
  	underFrac = tempUnderFrac;
  	
  	//Remove Integer
  	ll integerPart = (sqrt((double)underSqrt) + added) / ((double)underFrac);
  	intPart = integerPart;
  	added -= intPart * underFrac;
  	
  }
  
}



ll getPeriod(ll num)
{
	vector<ll> info;
	continuedFraction(num, info);
	for(int i = 1; i < 1000; i++)
	{
		bool valid = true;
		for(int j = 0; j < 1000; j++)
		{
			if(info.at(j % i) != info.at(j))
			{
				valid = false;
				break;
			}
		}
		if(valid)
		{
			return i;
		}
	}
	return 0;
}

bool ispandigital(vector<ll> &nums)
{
  ll digits[10];
  for(int i = 0; i < 10; i++)
  {
    digits[i] = 0;
  }
  for(int i = 0; i < nums.size(); i++)
  {
    ll temp = nums.at(i);
    while(temp > 0)
    {
      digits[temp % 10]++;
      temp /= 10;
    }
  }
  if(digits[0] != 0)
  {
    return false;
  }
  for(int i = 1; i < 10; i++)
  {
    if(digits[i] != 1)
    {
      return false;
    }
  }
  return true;
}

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

struct nChooseR{

	ll table[1000][1000];

	nChooseR() {
		for(ll i = 0; i < 1000; i++)
		{
			for(ll j = 0; j < 1000; j++)
			{
				table[i][j] = -1;
			}
		}
	}

	ll querry(ll n, ll r)
	{
		if(table[n][r] != -1)
		{
			return table[n][r];
		}
		
		if(n == r)
		{
			return 1;
		}
		if(r == 0)
		{
			return 1;
		}
		ll val = querry(n - 1, r - 1) + querry(n - 1, r);
		table[n][r] = val;
		return val;
	}
	
};

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


struct partitionFunction
{
    map<ll, ll> remember;
    
    
    //The number of ways you can add to a number
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
  ll sol = 1;
  for(int i = 0; i < 6; i++)
  {
    sol *= getDigit(pow(10, i));
  
  }
  cout << sol << endl;
   
  return 0;
}
