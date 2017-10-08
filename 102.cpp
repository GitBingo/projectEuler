#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

struct point
  {
  double x;
  double y;
  };

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

double min(double a, double b)
  {
  if (a < b)
    return a;
  return b;
  }

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////

double max(double a, double b)
  {
  if (a > b)
    return a;
  return b;
  }

////////////////////////////////////////////////////////////////////
//          Cross product of vectors a and b                      //
////////////////////////////////////////////////////////////////////

double cross(point a, point b)
  {
  return a.x * b.y - a.y * b.x;
  }

////////////////////////////////////////////////////////////////////
//      Is c on the line segment from a to b?                     //
//      Assumes c is on the line from a to b                      //
////////////////////////////////////////////////////////////////////

bool on(point a, point b, point c)
  {
  if (((min(a.x, b.x) <= c.x) && (c.x <= max(a.x, b.x))) &&
      ((min(a.y, b.y) <= c.y) && (c.y <= max(a.y, b.y))))
    return true;
     
  return false;
  }

////////////////////////////////////////////////////////////////////
//       Compute cross product of vector from a to b and          //
//       vector from b to c                                       //
//       Set to zero if close to zero                             //
////////////////////////////////////////////////////////////////////

double direction(point a, point b, point c)
  {
  point ab;
  point bc;
  double result;

  ab.x = b.x - a.x;
  ab.y = b.y - a.y;
  bc.x = c.x - b.x;
  bc.y = c.y - b.y;
  result =  cross(ab, bc);
  if (fabs(result) < 1.0e-6)
    result = 0.0;
  return result;
  }

////////////////////////////////////////////////////////////////////
//    Is the turn from a to b to c clockwise?                     //
////////////////////////////////////////////////////////////////////

bool turn(point a, point b, point c)
  {
  return (direction(a, b, c) > 0);
  }

////////////////////////////////////////////////////////////////////
//    Is the turn from p[0] to p[1] to p[2] clockwise?            //
////////////////////////////////////////////////////////////////////

bool clockwise(point p[])
  {
  return turn(p[0], p[1], p[2]);
  }

////////////////////////////////////////////////////////////////////
//     From text, page 937 (second edition)                       //
//     Does line segment from p1 to p2 intersect                  //
//     line segment from p3 to p4?                                //
////////////////////////////////////////////////////////////////////

bool intersect(point p1, point p2, point p3, point p4)
  {
  double d1;
  double d2;
  double d3;
  double d4;

  d1 = direction(p3, p4, p1);
  d2 = direction(p3, p4, p2);
  d3 = direction(p1, p2, p3);
  d4 = direction(p1, p2, p4);

  if ((((d1 > 0) && (d2 < 0)) || ((d1 < 0) && (d2 > 0))) &&
      (((d3 > 0) && (d4 < 0)) || ((d3 < 0) && (d4 > 0))))
    return true;

  if ((d1 == 0) && on(p3, p4, p1))
    return true;

  if ((d2 == 0) && on(p3, p4, p2))
    return true;

  if ((d3 == 0) && on(p1, p2, p3))
    return true;

  if ((d4 == 0) && on(p1, p2, p4))
    return true;

  return false;
  }

////////////////////////////////////////////////////////////////////
//          Area of polygon by adding/subtracting trapezoids      //
////////////////////////////////////////////////////////////////////

double area(point p[], int n)
  {
  int i;
  int j;
  double result;

  result = 0;
  for (i = 0; i < n; i++)
    {
    j = (i + 1) % n;
    result += p[i].x * p[j].y;
    result -= p[i].y * p[j].x;
    }
  return fabs(result / 2);
  }

////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////


int main()
{
	ll x1, x2, x3, x4, x5, x6;
	ll sol = 0;
	// read in the points make sure it intersect with one line
	while(cin >> x1 >> x2 >> x3 >> x4 >> x5 >> x6)
	{
	  point p1;
    point p2;
    point p3;

	  p1.x = x1;
	  p1.y = x2;
	  p2.x = x3;
	  p2.y = x4;
	  p3.x = x5;
	  p3.y = x6;
	  
	  point zero;
	  point farAway;
    zero.x = 0;
	  zero.y = 0;
	  farAway.x = 20000;
	  farAway.y = 10000;
	  
	  ll count = 0;
	  if(intersect(zero, farAway, p1, p2))
	  {
	    count++;
	  }
	  if(intersect(zero, farAway, p1, p3))
	  {
	    count++;
	  }
	  if(intersect(zero, farAway, p2, p3))
	  {
	    count++;
	  }
	  if(count % 2 == 1)
	  {
	    sol++;
	  }
	}
	cout << sol << endl;
  
  return 0;
}




