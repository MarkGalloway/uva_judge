/* UVa problem: 10819 Trouble of 13-Dots
 *
 * Topic: Dynamic Programming
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   0-1 Knapsack problem with credit card rebate of 200 if spending
 *   goes over 2000
 *
 * Solution Summary:
 *
 *   Top down Dynamic Programming with special condition to handle the
 *   credit card rebate.
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

using namespace std;

const int MAX_N = 101;
const int MAX_BUDGET = 10250;

int budget, N, F[MAX_N], P[MAX_N], memo[MAX_N][MAX_BUDGET];

/*
 *  Top-down DP
 */
int favor(int item, int rem) {

  if(item == N) return 0;     // Out of items
  if(memo[item][rem] != -1)   // Already calculated
    return memo[item][rem];

  // We break the 2000 limit
  if(P[item] + budget - rem > 2000) {
    if(rem - P[item] + 200 >= 0) {
        return memo[item][rem] = max(favor(item + 1, rem - P[item]) + F[item],
                       favor(item + 1, rem));
    }
    else {
      // Too expensive, skip
      return memo[item][rem] = favor(item + 1, rem);
    }
  }

  // Too expensive, skip
  if(P[item] > rem) {
    return memo[item][rem] = favor(item + 1, rem);
  }

  // To take or not to take, that is the question.
  return memo[item][rem] = max(favor(item + 1, rem - P[item]) + F[item],
                               favor(item + 1, rem));
}


int main() {
  // Process Test cases
  while (cin >> budget >> N) {
    memset(memo, -1, sizeof memo);

    // Read in the items
    int p, f;
    for (int i = 0; i < N; ++i) {
      cin >> p >> f;
      F[i] = f;
      P[i] = p;
    }

    // Calculate max favor Top Down
    cout << favor(0, budget) << endl;

  }

  return 0;
}