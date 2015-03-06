/* UVa problem: 10003 Cutting Sticks
 *
 * Topic: Dynamic Programming
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Find the mimimum cost cutting sequence of a stick length l
 *   with n cuts of specified length.
 *
 * Solution Summary:
 *
 *   Top Down dynamic programming
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
#include <cstring>
#include <limits>

using namespace std;

const int MAX_N = 55;

int l, n, lengths[MAX_N], memo[MAX_N][MAX_N];

/*
 * Calculate minimum cost of cutting
 */
int cut(int left, int right) {
  // Basecases
  if(left + 1 == right) return 0; // Nothing to cut
  if(memo[left][right] != -1) return memo[left][right]; // Already computed

  // Recursive Case
  int ans = std::numeric_limits<int>::max();

  for (int i = left + 1; i < right; ++i) {
    ans = min(ans, cut(left, i) + cut(i, right) + (lengths[right] - lengths[left]));
  }
  return memo[left][right] = ans;

}

int main() {

  while(1) {
    // length
    cin >> l;

    // End of cases
    if(l == 0)
      break;

    memset(memo, -1, sizeof memo);

    // Cuts
    cin >> n;

    // Build Lengths of n+1 sticks
    lengths[0] = 0;
    for (int i = 1; i <= n; ++i)
      cin >> lengths[i];
    lengths[n+1] = l;

    // Print solution
    cout << "The minimum cutting is " << cut(0, n+1) << "." << endl;

  }

  return 0;
}