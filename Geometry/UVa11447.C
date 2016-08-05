/* UVa problem: 11447 Reservoir Logs
 *
 * Topic: Geometry
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Given points for the cross section of a reservoir, initial water,
 *   water consumption, and rainfall, determine Lack/Excess of water
 *   and final percentage remaining in reservoir
 *
 * Solution Summary:
 *
 *   Area algorithm from the textbook, simple calculations on volume
 *
 * Used Resources:
 *
 *   Competitive Programming 3 (lots of code from the book ): )
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define EPS 1e-9

struct point { double x, y;   // only used if more precision is needed
  point() { x = y = 0.0; }                      // default constructor
  point(double _x, double _y) : x(_x), y(_y) {}        // user-defined
  bool operator == (point other) const {
   return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS)); } };

struct vec { double x, y;  // name: `vec' is different from STL vector
  vec(double _x, double _y) : x(_x), y(_y) {} };

vec toVec(point a, point b) {       // convert 2 points to vector a->b
  return vec(b.x - a.x, b.y - a.y); }

double dist(point p1, point p2) {                // Euclidean distance
  return hypot(p1.x - p2.x, p1.y - p2.y); }           // return double

// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {
  double result = 0.0;
  for (int i = 0; i < (int)P.size()-1; i++)  // remember that P[0] = P[n-1]
    result += dist(P[i], P[i+1]);
  return result; }

// returns the area, which is half the determinant
double area(const vector<point> &P) {
  double result = 0.0, x1, y1, x2, y2;
  for (int i = 0; i < (int)P.size()-1; i++) {
    x1 = P[i].x; x2 = P[i+1].x;
    y1 = P[i].y; y2 = P[i+1].y;
    result += (x1 * y2 - x2 * y1);
  }
  return fabs(result) / 2.0; }


typedef vector<point> vp;
vp points;

int main() {
  int cases, n, width;
  double initial, spent, gained;
  cin >> cases >> ws;

  while(cases--) {
    // Problemsetter: Maybe if I add as much whitespace as possible, this problem will be easier.
    // Solver: wtf, why?
    cin >> ws >> n >> ws;

    // Init
    points.clear();
    int x, y;

    // Read in points
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      points.push_back(point(x,y));
    }

    // Read in information
    cin >> width;
    cin >> initial >> spent >> gained;

    // Complete the polygon, if necessary
    if(!(points.back() == points.front()))
      points.push_back(points.front());

    // Compute volume
    double volume = area(points) * width;

    // Solve
    double water = volume * (initial/100);

    water -= spent;
    if(water < 0) {
      cout << "Lack of water. ";
      water = 0;
    }

    water += gained;
    if(water > volume) {
      cout << "Excess of water. ";
      water = volume;
    }

    int ans = water/volume * 100;
    cout << "Final percentage: " << ans << '%' << endl;

  }

  return 0;
}