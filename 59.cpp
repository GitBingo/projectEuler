#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

string commonWords[99] ={
"back",
"after",
"use",
"two",
"how",
"our",
"work",
"is",
"well",
"way",
"even",
"new",
"want",
"because",
"any",
"these",
"give",
"day",
"most",
"us",
"people",
"into",
"year",
"your",
"good",
"some",
"could",
"them",
"see",
"other",
"than",
"then",
"now",
"look",
"only",
"come",
"its",
"over",
"think"
"also",
"so",
"up",
"out",
"if",
"about",
"who",
"get",
"which",
"go",
"me",
"when",
"make",
"can",
"like",
"time",
"no",
"just",
"him",
"know",
"take",
"this",
"but",
"his",
"by",
"from",
"they",
"we",
"say",
"her",
"she",
"or",
"an",
"will",
"my",
"one",
"all",
"would",
"there",
"their",
"what",
"the",
"be",
"to",
"of",
"and",
"a",
"in",
"that",
"have",
"i",
"it",
"for",
"not",
"on",
"with",
"he",
"as",
"you",
"do",
"at"
};

string pass;
ll best;

bool findSubstr(string s, string substr)
{
	bool exists = s.find(substr) != std::string::npos;
	return exists;
}

bool decrypt(string key, vector<ll> &points)
{
	string s;
	
	//string *coomonWords = {"us", "most"};
	
	for(int i = 0; i < points.size(); i++)
	{
		char temp = (char)(points.at(i) ^ (int)key.at(i % 3));
		s += temp;
	}
	cout << key << endl;
	cout << s << endl;
	//ll pause;
	//cin >> pause;
	ll total = 0;
	for(int i = 0; i < 99; i++)
	{
		if(findSubstr(s, commonWords[i]))
		{
			if(total > best)
			{
				best = total;
				pass = key;
			}
		}
	}
	
}

bool decryptPrint(string key, vector<ll> &points)
{
	string s;
	
	//string *coomonWords = {"us", "most"};
	
	for(int i = 0; i < points.size(); i++)
	{
		char temp = (char)(points.at(i) ^ ((int)key.at(i % 3)));
		s += temp;
	}
	
	
	cout << s << endl;
	
}



int main()
{

	string decrypted = "(The Gospel of John, chapter 1) 1 In the beginning the Word already existed. He was with God, and he was God. 2 He was in the beginning with God. 3 He created everything there is. Nothing exists that he didn't make. 4 Life itself was in him, and this life gives light to everyone. 5 The light shines through the darkness, and the darkness can never extinguish it. 6 God sent John the Baptist 7 to tell everyone about the light so that everyone might believe because of his testimony. 8 John himself was not the light; he was only a witness to the light. 9 The one who is the true light, who gives light to everyone, was going to come into the world. 10 But although the world was made through him, the world didn't recognize him when he came. 11 Even in his own land and among his own people, he was not accepted. 12 But to all who believed him and accepted him, he gave the right to become children of God. 13 They are reborn! This is not a physical birth resulting from human passion or plan, this rebirth comes from God.14 So the Word became human and lived here on earth among us. He was full of unfailing love and faithfulness. And we have seen his glory, the glory of the only Son of the Father.";
	
	ll sum = 0;
	for(int i = 0; i < decrypted.size(); i++)
	{
		sum += decrypted.at(i);
	}
	cout << sum << endl;
	return 0;

	best = 0;
	ifstream fin("crypt.in");
	
	string key = "xor";
	
	vector<ll> points;
	ll temp;
	while(fin >> temp)
	{
		points.push_back(temp);
	}
	
	for(int i = 0; i < 26; i++)
	{
		for(int j = 0; j < 26; j++)
		{
			for(int k = 0; k < 26; k++)
			{
				key = "";
				//cout << i << " " << j << " " << k << endl;
				key += (char)(i + 'a');
				key += (char)(j + 'a');
				key += (char)(k + 'a');
				decrypt(key, points);
			}
		}
	}
	
	cout << pass << endl;
	cout << best << endl;
	//decryptPrint(pass, points);
	
	
	
	fin.close();
  return 0;
}




