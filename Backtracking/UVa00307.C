/* UVa problem: 307 Sticks
 *
 * Topic: Backtracking
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Given stick pieces, form as many equal length sticks as possible
 *   where the length of each stick is minimal
 *
 * Solution Summary:
 *
 *   Backtracking. Heavy Pruning.
 *
 * Used Resources:
 *
 *   Competitive Programming 3
 *   Consulted with Tamara Bain on April 10th after spending 30+ hours
 *   on this problem. She suggested some better pruning strategies.
 *   Wouldn't have been able to solve this on my own.
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef vector<bool> vb;

int N, length, num_sticks, stick_sum;
vi sticks;
vb used;

bool backtrack(int index, int current_length, int pieces_left) {

  // Basecase, we are out of sticks
  if(pieces_left == 0)
    return true;

  // BaseCase: Stick does not fit
  if(current_length > length) return false;

  // Shouldn't happen, sanity check
  if(current_length > length) cout << "wtf";

  bool success = false;

  // Recursive case: Build the stick
  for (int i = index; i < N; ++i) {
    // Prune: Stick is used
    if(used[i]) continue;

    // Mark used and select
    used[i] = true;
    int new_length = current_length + sticks[i];

    // If the next stick fits
    if(new_length == length) {
      success = backtrack(0, 0, pieces_left - 1);
    }
    // Completed a stick
    else {
      success = backtrack(i, new_length, pieces_left - 1);
    }

    if(success) break;

    used[i] = false;

    // Prune, first stick should not fail
    if(new_length == length) break;

    if(current_length == 0) break;


  }
  // Matching failed
  return success;
}

int main() {

  while (1) {
    cin >> N >> ws;

    // End of cases
    if(N == 0) break;

    // Init
    sticks.assign(N, 0);
    stick_sum = 0;

    // Read in the sticks
    for (int i = 0; i < N; ++i) {
      cin >> sticks[i];

      // Track the sum of sticks
      stick_sum += sticks[i];
    }

    sort(sticks.begin(), sticks.end(), greater<int>());

    for (int i = sticks[0]; i <= stick_sum; ++i) {

      //
      if(stick_sum % i != 0) continue;

      length = i;

      used.assign(N, false);

      if(backtrack(0, 0, N)) {
        // Solution found
        break;
      }

    }
    cout << length << endl;

  }

  return 0;
}