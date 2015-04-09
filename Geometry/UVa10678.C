/* UVa problem: 10678 The Grazing Cow
 *
 * Topic: Geometry
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Find the area of an elipse given 3 foci
 *
 * Solution Summary:
 *
 *   Straight-forward area of elipse calculation
 *
 * Used Resources:
 *
 *   Competitive Programming 3
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define PI acos(-1.0)

int main() {
  int cases, d, l;
  cin >> cases;

  while(cases--) {
    cin >> d >> l;

    double r1 = l/2.0;
    double dist = d/2.0;
    double r2 = sqrt(pow(r1, 2) - pow(dist, 2));
    double area = PI * r1 * r2;

    cout << setprecision(3) << fixed << area << endl;
  }
  return 0;
}