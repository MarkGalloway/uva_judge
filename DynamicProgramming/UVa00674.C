/* UVa problem: 00674 Coin Change
 *
 * Topic: Dynamic Programming
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Given a value, find the number of ways (canonical) to make change
 *   using coins {1, 5, 10, 25, 50}
 *
 * Solution Summary:
 *
 *   Top Down Dynamic Programming
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
#include <cstring>

using namespace std;

const int NUM_TYPES = 5;
const int coins[NUM_TYPES] = {1, 5, 10, 25, 50};
int memo[6][7500];

/*
 * Find the number of ways to make change
 */
int change(int type, int value) {
  // Basecases
  if(value == 0) return 1; // There is 1 way to make change for 0 cents
  if(value < 0)  return 0; // No ways
  if(type == NUM_TYPES) return 0; // Out of coins

  int &r = memo[type][value];

  // Already computed
  if(r != -1) return r;

  // Recursive Case
  return r = change(type + 1, value) + change(type, value - coins[type]);

}

int main() {
  int n;
  memset(memo, -1, sizeof memo);

  while(cin >> n)
    cout << change(0, n) << endl;

  return 0;
}