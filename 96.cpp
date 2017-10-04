#include <bits/stdc++.h>


using namespace std;

typedef long long ll;

ll bored[9][9];

ll tempSol;

//This function given a position on the bored will return all
//the possible numbers that can be stored in that position and
//store it in data
void getValid(ll x, ll y, vector<ll> &data)
{
	bool seen[10] = {false};
	//calculate the top left corner or the 3x3 box
	ll xStart = ((ll)(x / 3)) * 3;
	ll yStart = ((ll)(y / 3)) * 3;
	//loop across row and colum and box
	for(int i = 0; i < 9; i++)
	{
		seen[bored[x][i]] = true;
		seen[bored[i][y]] = true;
		seen[bored[xStart + i / 3][yStart + i % 3]] = true;
	}
	//find all numbers that did not appear
	for(int i = 1; i < 10; i++)
	{
		if(!seen[i])
			data.push_back(i);
	}
}

//A recursive function to solve a sudoko puzzel
//Step in every position and check all the possibilities
void solve(ll x, ll y)
{
	//If you have reached the end of the puzzel stop and record answer
	if(y == 9 && x == 0)
	{
		tempSol = 100 * bored[0][0] + 10 * bored[0][1] + bored[0][2];
		return;
	}
	
	//calculate the next position to move to
	ll startX = x + 1;
	ll startY = y;
	if(startX > 8)
	{
		startX = 0;
		startY = y + 1;
	}
	//see if you can place a number in that position
	if(bored[x][y] == 0)
	{
		vector<ll> possible;
		//find all the possible value that can go in the new position
		getValid(x, y, possible);
		// try all the possible positions and recurse
		for(ll i = 0; i < possible.size(); i++)
		{
			bored[x][y] = possible.at(i);
			solve(startX, startY);
		}
		bored[x][y] = 0;
	}else
	{
		//if i cant place anything in the new position just move on
		solve(startX, startY);
	}
}

int main()
{

	string s;
	//read in the first string and trash it
	ll sol = 0;
	while(getline(cin, s))
	{
		vector<ll> data;		
		//read in the sudoko puzzel
		for(int i = 0; i < 9; i++)
		{
			string s;
			cin >> s;
			for(int j = 0; j < 9; j++)
			{
				bored[i][j] = s.at(j) - '0';
			}
		}
		cin.ignore();
		//solve the bored
		solve(0,0);
		//record the sum of the top 3 digit of the bored
		sol += tempSol;
  }
  cout << sol << endl;
  
  return 0;
}




