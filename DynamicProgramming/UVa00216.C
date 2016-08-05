/* UVa problem: 00216 Getting in line
 *
 * Topic: Dynamic Programming
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Connect N computers using the shortest amount of cable.
 *   Travelling Salesman variation.
 *
 * Solution Summary:
 *
 *   Top-down Dynamic Programming. Some issues with the algorithm presented
 *   in the book, as starting node was sometimes not optimal. Got an AC by
 *   trying all nodes as starting nodes and using the shortest result.
 *   Not much of a slowdown doing this due to the DP table.
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
#include <cstring>
#include <limits>
#include <algorithm>
#include <iomanip>

using namespace std;

int n, x[10], y[10];
double dist[10][10];
double memo[10][1 << 10];

/*
 * Preforms traveling salesman to find the length of
 * the shortest path
 */
double tsp(int pos, int bitmask) {
  // Basecases
  if(bitmask == ((1 << n) - 1))  // All nodes connected
    return 0;

  if(memo[pos][bitmask] != -1.0) // Already Calculated
    return memo[pos][bitmask];

  // Recursive case
  double ans = 200000;
  for (int i = 0; i < n; ++i)
    if(i != pos && !(bitmask & (1 << i)))
      ans = min(ans, dist[pos][i] + tsp(i, bitmask | (1 << i)));

  return memo[pos][bitmask] = ans;
}

/*
 * Recreates the shortest path using the DP table and prints
 * the path weights
 */
void print_tsp(int pos, int bitmask) {
  // Basecase
  if(bitmask == ((1 << n) - 1)) // All nodes explored
    return;

  double ans;
  for (int i = 0; i < n; ++i) {
    ans = dist[pos][i] + tsp(i, bitmask | (1 << i));
    if(ans == memo[pos][bitmask]) {

      // Print answer
      cout << "Cable requirement to connect (" << x[pos] << "," << y[pos] << ") ";
      cout << "to (" << x[i] << "," << y[i] << ") is "<< dist[pos][i] << " feet." << endl;

      print_tsp(i, bitmask | (1 << i));
      break;
    }
  }
}


int main() {
  int cases = 0;

  while(1) {
    cin >> n;

    if(n == 0) break; // End of Cases

    // Read in the locations
    for (int i = 0; i < n; ++i)
      cin >> x[i] >> y[i];

    // Build distance table
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        dist[i][j] = sqrt(pow(x[i]-x[j], 2) + pow(y[i]-y[j], 2)) + 16;

    // Initialize dp table to -1
    fill(memo[0], memo[0] + 10 * (1<<10), -1.0);

    // Generate Solution
    double total = 200000;
    int index = 0;
    for (int i = 0; i < n; ++i) {
        double ans = tsp(i, (1 << i));
        if(total > ans) {
          total = ans;
          index = i;
        }
    }

    // Print Solution
    cout << fixed << setprecision(2);

    // Print Header
    cout << "**********************************************************" << endl;
    cout << "Network #" << ++cases << endl;

    // Print node to node measurements
    print_tsp(index, (1 << index));

    // Print total measurement
    cout << "Number of feet of cable required is ";
    cout << total << "." << endl;

  }

  return 0;
}