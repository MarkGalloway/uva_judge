/* UVa problem: 00729 The Hamming Distance Problem
 *
 * Topic: Backtracking
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   For N bits, generate all bit strings that are hamming
 *   distance H from 0
 *
 * Solution Summary:
 *
 *   This is a pretty straight-forward backtracking problem.
 *   I had originally started from 0 and started setting H bits to
 *   1's and then printing them, but the output was actually being
 *   printed mirrored, so I had to start from 1 and flip N-H bits
 *   to 0.
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

int N, H;

void backtrack(int bits, int dist, int index) {
  // Base Case: Hamming Distance is H
  if(dist == H) {
    // Print out answer
    for (int i = 0; i < N; ++i) {
      int bit = bits & (1 << i);
      if(bit)
        cout << 1;
      else
        cout << 0;
    }
    cout << endl;
  }

  // Recursive Case: Toggle a bit
  for (int i = index; i < N; ++i) {
    int bit = bits & (1 << i);
    // If the bit is set
    if(bit)
      // Clear and Recurse
      backtrack(bits & ~(1 << i), dist + 1, i + 1);
  }
}

int main() {

  int cases;
  cin >> cases >> ws;

  while(cases--) {

    cin >> ws >> N >> H >> ws;

    int bits = 0;
    for (int i = 0; i < N; ++i) {
      bits |= (1 << i);
    }

    // flip it since we are working backward
    H = N-H;

    backtrack(bits, 0, 0);

    if(cases)
      cout << endl;

  }

  return 0;
}