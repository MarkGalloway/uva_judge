/* UVa problem: 11172 Relational Operators
 *
 * Topic: Other
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Print out the relational operator for the comparison of the two ints
 *
 * Solution Summary:
 *
 *   Straight-Forward comparison and print
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
  int cases;
  int a, b;
  cin >> cases;

  while(cases--) {
    cin >> a >> b;
    (a < b)? cout << '<' : (a > b)? cout << '>' : cout << '=';
    cout << endl;
  }
  return 0;
}