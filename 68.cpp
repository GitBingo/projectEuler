#include <iostream>
#include <fstream>
#include <vector>

using namespace std;


typedef long long ll;

vector<ll> first;
vector<ll> second;

struct theThing
{
	vector<ll> inner;
	vector<ll> outer;
};

void generate(ll num)
{
	//cout << "Generate " << num << endl;
	first.clear();
	second.clear();
	ll added = 14 - num;
	ll other = 0;
	other++;
	added--;
	while (added != 0)
	{
		if (other >= added)
		{
			return;
		}
		if (other != num && added <= 10 && other <= 10)
		{
			first.push_back(added);
			second.push_back(other);
		}
		other++;
		added--;
	}
}

bool checkThing(theThing *newThing)
{
	for (int i = 0; i < 5; i++)
	{
		ll o1 = newThing->inner.at(i);
		ll o2 = newThing->inner.at(i);
		ll o3 = newThing->inner.at(i % 5);
		if ( o1 == 0 || o2 == 0 || o3 == 0 || o1 + o2 + o3 != 14 )
		{
			return false;
		}
	}
	return true;
}

bool repeatedNumber(theThing *newThing)
{
	vector<ll> visitedNum(20, 0);
	for (int i = 0; i < 5; i++)
	{
		visitedNum.at(newThing->inner.at(i))++;
	}
	for (int i = 0; i < 5; i++)
	{
		visitedNum.at(newThing->outer.at(i))++;;
	}
	bool good = true;
	for (int i = 1; i < visitedNum.size(); i++)
	{
		if (visitedNum.at(i) != 0 && visitedNum.at(i) != 1)
		{
			good = false;
			break;
		}
	}
	return good;

}

void permuteThing(theThing *newThing, ll loc)
{
	if (!repeatedNumber(newThing))
	{

		//cout << "here" << endl;
		return;
	}
	/*//cout << "here" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << newThing->inner.at(i) << " ";
	}
	cout << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << newThing->outer.at(i) << " ";
	}
	cout << endl << endl;


	ll pause;
	cin >> pause;
	*/
	if (loc == 5)
	{
		if (newThing->inner.at(0) + newThing->inner.at(1) + newThing->outer.at(0) == 14)
		{
			for (int i = 0; i < 5; i++)
			{
				cout << newThing->inner.at(i) << " ";
			}
			cout << endl;
			for (int i = 0; i < 5; i++)
			{
				cout << newThing->outer.at(i) << " ";
			}
			cout << endl << endl;
			
		}
		return;
	}
	//cout << loc << endl;
	ll testVal = newThing->inner.at(loc);
	if (testVal == 0)
	{
		cout << "here" << loc << endl;
		testVal = 2;
	}
	generate(testVal);
	//cout << "Test Val " << testVal << endl;;
	//cout << "Size " << first.size() << endl;;
	ll old1 = newThing->inner.at((loc + 1) % 5);
	ll old2 = newThing->outer.at(loc);
	for (int i = 0; i < first.size(); i++)
	{
		//cout << "i " << i << endl;
		newThing->inner.at((loc + 1) % 5) = first.at(i);
		newThing->outer.at(loc) = second.at(i);
		permuteThing(newThing, loc + 1);

		generate(testVal);
		newThing->inner.at((loc + 1) % 5) = second.at(i);
		newThing->outer.at(loc) = first.at(i);
		permuteThing(newThing, loc + 1);

		generate(testVal);
		newThing->inner.at((loc + 1) % 5) = old1;
		newThing->outer.at(loc) = old2;
	}
}



int main()
{
	theThing *newThing = new theThing();
	newThing->inner.resize(5, 0);
	newThing->outer.resize(5, 0);

	for (int i = 2; i < 3; i++)
	{
		//newThing->inner.at(0) = i;
		permuteThing(newThing, 0);

	}
	

	return 0;
}