#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
	//a>b
	
	//   x    x-1	   1
	//  --- * --- = ---
	//   n    n-1	   2
	
	//    1 + sqrt(1+2*(n^2-n))
	//x = ---------------------
	//             2
	
	//Now we need to figure out when 1+2*(n^2-n) formes a perfect square
	//1+2*(n^2-n) = (n-1)^2+n^2
	
	//We relize at this point that we are dealing with pathogorean triples or
	//(n-1)^2+n^2 = k^2
	
	//we know if n^2+(n-1)^2=k^2 then
	//n = a^2-b^2, (n-1) = 2*a*b
  //1 = a^2-b^2 - 2*a*b
	//solve for a in terms of b
	//b + sqrt(2*b*b+1) = a
	
	//we need to find the first time 2*b*b+1 = k^2 and 2*a*b > 10^12
	//the for loop does that below, we print out the number and that number
	//is n, go to wolfram alpha and plag that number into the equation above
	//and you are done!
	
	for(ll b = 1; true; b++)
	{
		ll temp = 2*b*b + 1;
		ll sqrtN = sqrt(temp);
		if(sqrtN * sqrtN == temp)
		{
			ll a = b + sqrtN;
			cout << "a " << a << " b " << b << endl;
			if(2 * b * (a) > pow(10, 12))
			{
				ll n = 2 * b * (a);
				ll n1 = a*a-b*b;
				if( n1 > n)
					swap(n,n1);
				cout << n << endl;
				return 0;
			}
		}
	}
  
  return 0;
}




