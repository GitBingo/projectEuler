#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

double matrix[1000][1000];

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

//This function takes a series of points
//If you had 3 points and aX^2+b^x+c = 1
//Then you can plug the points into the equation
//and solve for a,b,c using Row reduce esolont form
void coef(vector<ll> &x, vector<ll> &y)
{
  ll n = x.size();
  for(ll i = 0; i < n; i++)
  {
    for(ll j = 0; j <= n; j++)
    {
      if(j == n)
      {
        matrix[i][j] = y.at(i);
        continue;
      }
      matrix[i][j] = pow(x.at(i), j);
    }
  }
  RowReduce(n, n + 1);
  
}

//After the polynomial has been created this function will
//Plug in the next value to give the number we are looking for
//sum those up and we are done
ll getVal(vector<ll> &x, vector<ll> &y, ll n)
{ 
  //cout << n << endl;
  ll sol = 0;
  coef(x, y);
  for(ll i = 0; i < x.size(); i++)
  {
     sol += pow(n, i) * matrix[i][x.size()];
  }
  return sol;
}

ll u(ll n)
{
  return 1 - n + pow(n,2) - pow(n,3) + pow(n,4) - pow(n,5) + pow(n,6) - pow(n,7)
        + pow(n,8) - pow(n,9) + pow(n,10);
  //return pow(n, 3);
}

int main()
{
	vector<ll> x;
	vector<ll> y;
	ll sol = 1;
	for(ll i = 1; i <= 10; i++)
	{
	  x.push_back(i);
	  y.push_back(u(i));
	  
	  cout << u(i + 1) << " " << getVal(x, y, i + 1) << endl;
	  
	  sol += getVal(x, y, i + 1);
	}
  cout << sol << endl;
  
  
  return 0;
}




