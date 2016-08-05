/* UVa problem: 10689 Yet Another Number Sequence
 *
 * Topic: Arithmetic
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *  Print the last m digits of a modified fibonacci sequence number
 *
 * Solution Summary:
 *
 *   Use Pisano Period to only calculate a small portion of the modified
 *   fibonacci sequence.
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
#include <cmath>

using namespace std;

int a, b, n, m;

int memo[15002];
int pisano_period[] = {0, 60, 300, 1500, 15000};
int mod[] = {1, 10, 100, 1000, 10000};

int main() {
  int cases;
  cin >> cases >> ws;

  while(cases--) {
    cin >> a >> b >> n >> m >> ws;

    int index = n % pisano_period[m];
    int pisano = min(pisano_period[m], index);

    memo[0] = a % mod[m];
    memo[1] = b % mod[m];

    // Iteratively build fibonnaci up to pisano period max
    for (int i = 2; i <= pisano; ++i)
      // We only need m digits, so avoid overflow
      memo[i] = (memo[i-1] + memo[i-2]) % mod[m];

    // Print Solution
    cout << memo[index] << endl;

  }
  return 0;
}
