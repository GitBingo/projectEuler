#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


ll maxN;
ll pick;
ll pickb;

ll total;

bool good(vector<ll> &a, vector<ll> &b)
{
	bool aBig = false;
	bool bBig = false;
	if(a.size() != b.size())
	{
		return false;
	}
	for(ll i = 0; i < a.size(); i++)
	{
		if(a.at(i) > b.at(i))
			aBig = true;
		if(a.at(i) < b.at(i))
			bBig = true;
	}
	if(aBig && bBig)
		return true;
	else false;
}

void permuteItB(vector<ll> &a, vector<ll> &b, vector<bool> &vis, ll curr, ll prev)
{
	if(curr == pickb)
	{
		
		if(good(a,b))
		{
			total++;
		}
		return;
	}
	
	
	for(ll i = prev; i < maxN; i++)
	{
		if(!vis.at(i))
		{
			b.push_back(i);
			vis.at(i) = true;
			permuteItB(a, b, vis, curr + 1, i);
			b.pop_back();
			vis.at(i) = false;
		}
	}
	
}

void permuteIt(vector<ll> &a, vector<ll> &b, vector<bool> &vis, ll curr, ll prev)
{
	if(curr == pick)
	{
		permuteItB(a, b, vis, 0, 0);
		return;
	}
	
	
	for(ll i = prev; i < maxN; i++)
	{
		if(!vis.at(i))
		{
			a.push_back(i);
			vis.at(i) = true;
			permuteIt(a, b, vis, curr + 1, i);
			a.pop_back();
			vis.at(i) = false;
		}
	}
	
}

//A subset does not need to be checked if all the numbers in that subset
//are bigger than the numbers in the other, ex
//a>b>c>d>e>f if we have a,c,e and b,d,f, we know a>b, c>d, e>f, so we don't 
//need to check, otherwise we do. brute force, check all the possibilities 
//permutations
int main()
{
	total = 0;
	ll n = 12;
	for(ll i = 1; 2*i <= n; i++)
	{
	 	maxN = n;
	 	pick = i;
	 	pickb = i;
		vector<ll> a;
		vector<ll> b;
		vector<bool> vis(100, false);
		permuteIt(a, b, vis, 0, 0);
	}
	cout << total / 2 << endl;
  return 0;
}




