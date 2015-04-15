/* UVa problem: 12279 Emoogle Balance
 *
 * Topic: Other
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Perform a running tally based on input and print it
 *
 * Solution Summary:
 *
 *   Straight-Forward
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
  int cases = 0, n, balance, temp;

  while(1) {
    cin >> n;

    // End of Cases
    if(n == 0) break;

    balance = 0;

    // Read inputs
    for (int i = 0; i < n; ++i) {
      cin >> temp;

      if(temp) balance++;
      else balance--;
    }

    cout << "Case " << ++cases << ": " << balance << endl;
  }
  return 0;
}