/* UVa problem: 11727 Cost Cutting
 *
 * Topic: Other
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Find and print the median
 *
 * Solution Summary:
 *
 *   Straight forward. Sort. Print median.
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
#include <algorithm>

using namespace std;

int main() {
  int cases, num = 0;
  cin >> cases;

  while(cases--) {
    int salaries[3];

    cin >> salaries[0] >> salaries[1] >> salaries[2];

    sort(salaries, salaries + 3);

    cout << "Case " << ++num << ": " << salaries[1] << endl;

  }
  return 0;
}