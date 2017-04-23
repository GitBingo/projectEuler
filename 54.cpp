#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct hand
{
	vector<ll> data;
	bool sameSuit;

};

//greatest is 14
ll highCard(hand *h)
{
	ll largest = 0;
	//cout << "Here" << endl;
	for(int i = 0; i < h->data.size(); i++)
	{
		if(h->data.at(i) > 0 && i > largest)
		{
			largest = i;
		}
	}
	return largest;
}

//bounded by 15+13 = 28
ll pairCards(hand *h)
{
	//bounded by 13
	ll largest = -1;
	for(int i = 0; i < h->data.size(); i++)
	{
		if(h->data.at(i) == 2 && i > largest)
		{
			largest = i;
		}
	}
	
	if(largest > -1)
	{
		return 15 + largest;
	}
	return 0;
}


//bounded by 30 + 20 * 13 + 13 = 303
ll twoPair(hand *h)
{
	//bounded by 14
	ll first = -1;
	for(int i = 0; i < h->data.size(); i++)
	{
		if(h->data.at(i) == 2 && i > first)
		{
			first = i;
		}
	}
	
	
	ll second = -1;
	for(int i = 0; i < h->data.size(); i++)
	{
		if(h->data.at(i) == 2 && i > second && i != first)
		{
			second = i;
		}
	}
	//cout << "First " << first << " Second " << second << endl;
	if(first != second && first > -1 && second > -1 )
	{
		return 30 + 20 * first + second;
	}
	return 0;
}

//bounded by 330+13=343
ll treeOfAKind(hand *h)
{
	//bounded by 13
	ll largest = -1;
	for(int i = 0; i < h->data.size(); i++)
	{
		if(h->data.at(i) == 3 && i > largest)
		{
			largest = i;
		}
	}
	
	if(largest > -1)
	{
		return 330 + largest;
	}
	return 0;
}


//bounded by 350 + 13 = 363
ll straight(hand *h)
{
	//bounded by 13
	ll largest = -1;
	ll start = -1;
	for(int i = 0; i < h->data.size(); i++)
	{
		if(h->data.at(i) > 0)
		{
			start = i;
			break;
		}
	}
	
	for(int i = start; i < start + 5; i++)
	{
		if(h->data.at(i) != 1)
		{
			return 0;
		}
	}
	return 350 + start + 4;
}

//bounded by 400+13 = 413
ll flush(hand *h)
{
	if(h->sameSuit)
	{
		return 400 + highCard(h);
	}else
	{
		return 0;
	}
}
//bounded by 450 + 343*20+28 = 7338
ll fullHouse(hand *h)
{
	if(treeOfAKind(h) != 0 && pairCards(h) != 0)
	{
		return 450 + treeOfAKind(h)*20 + pairCards(h);
	}
	return 0;
}

//bounded by 8000+13=8013
ll fourOfAKind(hand *h)
{
	//bounded by 13
	ll largest = -1;
	for(int i = 0; i < h->data.size(); i++)
	{
		if(h->data.at(i) == 4 && i > largest)
		{
			largest = i;
		}
	}
	
	if(largest > -1)
	{
		return 8000 + largest;
	}
	return 0;
}

//bounded by 8500 + 13
ll straightFlush(hand *h)
{
	//bounded by 13
	if(straight(h) != 0 && flush(h) != 0)
	{
		return 8500 + highCard(h);
	}
	return 0;
}

//bounded by 100000
ll royalFlush(hand *h)
{
	if(flush(h) != 0 && h->data.at(13) == 1 && h->data.at(12) == 1 && 
			h->data.at(11) == 1 && h->data.at(10) == 1 && h->data.at(9) == 1)
			{
				return 100000;
			}
	return 0;

}

ll getCardVal(char c)
{
	if((c - '0') < 10 && (c - '0') > 0)
	{
		return (c - '0');
	}
	if(c == 'T')
	{
		return 10;
	}
	if(c == 'J')
	{
		return 11;
	}
	if(c == 'Q')
	{
		return 12;
	}
	if(c == 'K')
	{
		return 13;
	}
	if(c == 'A')
	{
		return 14;
	}
	return 0;
}

void buildHand(hand *h, string s1, string s2, string s3, string s4, string s5)
{
	if(s1.at(1) == s2.at(1) && s1.at(1) == s3.at(1) && s1.at(1) == s4.at(1) && 
	s1.at(1) == s5.at(1))
	{
		h->sameSuit = true;
	}else
	{
		h->sameSuit = false;
	}
	for(int i = 0; i < 15; i++)
	{
		h->data.push_back(0);
	}
	
	h->data.at(getCardVal(s1.at(0)))++;
	h->data.at(getCardVal(s2.at(0)))++;
	h->data.at(getCardVal(s3.at(0)))++;
	h->data.at(getCardVal(s4.at(0)))++;
	h->data.at(getCardVal(s5.at(0)))++;
	/*for(int i = 0; i < h->data.size(); i++)
	{
		cout << h->data.at(i) << " ";
	}
	cout << endl;*/
}

ll getHanfValue(hand *h)
{
	if(royalFlush(h) != 0)
	{
		return royalFlush(h);
	}
	if(straightFlush(h) != 0)
	{
		return straightFlush(h);
	}
	if(fourOfAKind(h) != 0)
	{
		return fourOfAKind(h);
	}
	if(fullHouse(h) != 0)
	{
		return fullHouse(h);
	}
	if(flush(h) != 0)
	{
		return flush(h);
	}
	if(straight(h) != 0)
	{
		return straight(h);
	}
	if(treeOfAKind(h) != 0)
	{
		return treeOfAKind(h);
	}
	if(twoPair(h) != 0)
	{
		return twoPair(h);
	}
	if(pairCards(h) != 0)
	{
		return pairCards(h);
	}
	if(highCard(h) != 0)
	{
		return highCard(h);
	}
	return 0;
}

int main()
{
	ifstream fin("hands.in");
	string s1,s2,s3,s4,s5,s6,s7,s8,s9,s10;
	ll total = 0;
	for(int i = 0; fin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6 >> s7 >> s8 >> s9 >> s10
						; i++)
	{
		hand *h1 = new hand();
		buildHand(h1, s1,s2,s3,s4,s5);

		/*cout << "Pusing " << endl;
		ll pause;
		cin >> pause;
	*/
		hand *h2 = new hand();
		buildHand(h2,s6,s7,s8,s9,s10);
		ll val1 = getHanfValue(h1);
		ll val2 = getHanfValue(h2);
		if(val1 > val2)
		{
			total++;
		}
		if(val1 == val2)
		{	
			ll val = 0;
			cout << endl << "I need help, type 1 is player 1 wins, otherwise 0, on case :" << i << endl;
			cout << s1 << " " << s2 << " " << s3 << " " << s4 << " " << s5 << " Val:" << val1  << endl;
			cout << s6 << " " << s7 << " " << s8 << " " << s9 << " " << s10 << " Val:" << val2 << endl;
			cin >> val;
			total += val;
		}
	}
	cout << total << endl;
  fin.close();
  return 0;
}





