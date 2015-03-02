/* UVa problem: 231 Testing the CATCHER
 *
 * Topic: Dynamic Programming
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Find the Longest Decreasing Subsequence and print it's length
 *
 * Solution Summary:
 *
 *   I modified the O(n logk) Longest Increasing Subsequence algortithm
 *   as presented in the textbook to find the Longest Decreasing
 *   Subsequence(LDS). Basically, just maintaining a sorted array L which
 *   where L[i] is the largest ending value of length-i LDS. The largest length
 *   of L is the LDS.
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

const int MAX_N = 100000;

int main() {
  int n, test = 0;

  while(1) {
    cin >> n;

    // End of Cases
    if(n == -1)
      break;

    // Newline between output of cases
    if(test)
      cout << endl;

    // Initialize
    int count = 0;
    int heights[MAX_N], L[MAX_N];

    // Read in data for this case
    heights[count++] = n;
    cin >> n;
    while(n != -1) {
      heights[count++] = n;
      cin >> n;
    }

    // Longest Decreasing Subsequence
    int lds = 0;
    for (int i = count-1; i >= 0; --i) {
      // Find the first index i in L where L[i] > height[i]
      int pos = upper_bound(L, L + lds, heights[i]) - L;

      // Update the element
      L[pos] = heights[i];

      // update LDS length
      if(pos + 1 > lds)
        lds = pos + 1;
    }

    // Print Solution
    cout << "Test #" << ++test << ":" << endl;
    cout << "  maximum possible interceptions: " << lds << endl;
  }

  return 0;
}