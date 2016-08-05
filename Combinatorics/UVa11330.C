/* UVa problem: 11330 Andy's Shoes
 *
 * Topic: Combinatorics
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Given a list of unordered pairs, determine the least amount of swaps
 *   necessary to order the pairs
 *
 * Solution Summary:
 *
 *   Store shoes and locations of each pair member
 *   greedily select and swap desired shoe pair in linear scan fashion
 *
 * Used Resources:
 *
 *   Howard Cheng's Hint
 *
 *   Discussed with Tamara Bain about how this may or may not be
 *   Cycle Decomposition as suggested by Howard Cheng
 *   She told me she used a greedy approach and I ended up doing so as well
 *   since it does not apear to be cycle decomposition.
 *
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> vi;

vi shoes;
vi location1;
vi location2;


int swap_shoes() {
  int swaps = 0;

  for (int i = 1; i < shoes.size(); i += 2) {
    // Shoe pair is already matching
    if (shoes[i] == shoes[i+1]) continue;

    // Swap second pair with desired shoe
    int desired = shoes[i];
    int undesired = shoes[i+1];

    // it must be at location 2 (2nd shoe)
    int desired_index = (location2[desired] > location1[desired])?
                         location2[desired] : location1[desired];

    // Swap
    ++swaps;
    shoes[desired_index] = undesired;
    // shoes[i+1] = desired; // irrelevent update

    // Update undesired location
    if(location1[undesired] == i+1) location1[undesired] = desired_index;
    else                            location2[undesired] = desired_index;

}

  return swaps;
}


int main() {
  int cases, n;
  cin >> cases;

  while(cases--) {
    cin >> n;
    shoes.assign    (2*n + 1, int(0));
    location1.assign(10001, int(0));
    location2.assign(10001, int(0));

    // Read in shoe arrangement
    int shoe;
    for (int i = 1; i < 2*n+1; ++i) {
      cin >> shoe;
      // Store shoe order
      shoes[i] = shoe;

      // Record location of this shoe-type
      if (location1[shoe] == 0) location1[shoe] = i;
      else                      location2[shoe] = i;
    }

    // Sort shoes
    int ans = swap_shoes();

    cout << ans << endl;
  }
  return 0;
}