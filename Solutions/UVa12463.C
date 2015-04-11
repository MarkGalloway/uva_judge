/* UVa problem: 12463 Little Nephew
 *
 * Topic: Combinatorics
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Compute the number of different outfits based on input
 *
 * Solution Summary:
 *
 *   Compute the number of permutations
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

using namespace std;

int main() {
  int a,b,c,d,e;

  while(1) {
    cin >> a >> b >> c >> d >> e >> ws;

    // End of Cases
    if(a == 0) break;

    // Print solution
    cout << a * b * c * d * d * e * e << endl;
  }

  return 0;
}