#include <bits/stdc++.h>
//IMPORTANT digits have to be between 0-9, and it has to be a reprdering

using namespace std;

typedef long long ll;

vector<char> caracters;

vector<ll> theNums;

ll maxN;

bool seen[10000];

ll solution;

string s1;
string s2;
bool good;

ll getValue(char c)
{
	for(ll i = 0; i < caracters.size(); i++)
	{
		if(caracters.at(i) == c)
			return theNums.at(i);
	}
	return 0;
}


//This function compute every permutastion assigning every digit
//to a number and checking it
void getCombo()
{
	if(theNums.size() >= caracters.size())
	{
		ll num1 = getValue(s1.at(0));
		ll num2 = getValue(s2.at(0));
		if(num1 == 0 || num2 == 0)
			return;
		for(ll i = 1; i < s1.size(); i++)
		{
			num1 *= 10;
			num1 += getValue(s1.at(i));
		}
		for(ll i = 1; i < s2.size(); i++)
		{
			num2 *= 10;
			num2 += getValue(s2.at(i));
		}
		if(num1 <= solution && num2 <= solution)
		{
			return;
		}
		
		ll sqrtNum1 = std::sqrt(num1);
		ll sqrtNum2 = std::sqrt(num2);
		if(sqrtNum1 * sqrtNum1 != num1 || sqrtNum2 * sqrtNum2 != num2)
			return;
		
		if(num1 > solution)
			solution = num1;
		if(num2 > solution)
			solution = num2;
		for(ll i = 0; i < theNums.size(); i++)
		{
			cout << theNums.at(i) << " ";
		}
		cout << num1 << " " << num2 << " " << s1 << " " << s2;
		cout << endl;
		return;
	}
	for(ll i = maxN - 1; i >= 0; i--)
	{
		if(!seen[i])
		{
			seen[i] = true;
			theNums.push_back(i);
			getCombo();
			seen[i] = false;
			theNums.pop_back();
		}
	}
	
}
ll maxCount;
//sets all the variables for getCombo and then calls getCombo
void compute(string s11, string s22)
{
	good = true;
	for(ll i = 0; i < maxN; i++)
	{
		seen[i] = false;
	}
	
	caracters.clear();
	for(ll i = 0; i < s11.size(); i++)
	{
		caracters.push_back(s11.at(i));
	}
	for(ll i = 0; i < s22.size(); i++)
	{
		caracters.push_back(s22.at(i));
	}
	std::sort(caracters.begin(), caracters.end());
	caracters.erase(unique(caracters.begin(), caracters.end()), caracters.end());
	if(caracters.size() > maxCount)
	{
		maxCount = caracters.size();
	}
	s1 = s11;
	s2 = s22;
	getCombo();
}

//Make sure the string n1 is a reordering of n2
bool sameButReordered(string n1, string n2)
{
	vector<char> num1;
	vector<char> num2;
	for(ll i = 0; i < n1.size(); i++)
	{
		num1.push_back(n1.at(i));
	}
	for(ll i = 0; i < n2.size(); i++)
	{
		num2.push_back(n2.at(i));
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



int main()
{
	maxN = 10;
	maxCount = 0;
	solution = 0;
	
	vector<string> theString;
	string temp;
	//reads the input from cin and then try every possibility
	//Brute force try every possibility
	while(cin >> temp)
	{
		theString.push_back(temp);
	}
	for(ll i = 0; i < theString.size(); i++)
	{
		for(ll j = i + 1; j < theString.size(); j++)
		{
			if(sameButReordered(theString.at(i), theString.at(j)))
			{
				compute(theString.at(i), theString.at(j));
				cout << theString.at(i) << " " << theString.at(j) << endl;
			}
		}
	}
	cout << solution << endl;
	
	
  
  return 0;
}




