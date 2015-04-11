/* UVa problem: 821 Page Hopping
 *
 * Topic: Graph Algorithms
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   All Pairs Shortest Path
 *   determine the average shortest path length between every pair of nodes, accurate
 *   to three fractional digits
 *
 * Solution Summary:
 *
 *   Floyd-Warshall's
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
#include <iomanip>
#include <algorithm>
#include <bitset>

using namespace std;

#define INF 1000000000
#define MAX 101

int main() {
  int a, b, AdjMatrix[MAX][MAX];
  bool SeenList[MAX];
  int num_cases = 0;

  while(1) {
    cin >> a >> b;

    // End of Cases
    if(a == 0 && b == 0) break;

    // Init
    for (int i = 0; i < MAX; ++i) {
      for (int j = 0; j < MAX; ++j)
        AdjMatrix[i][j] = INF;
      AdjMatrix[i][i] = 0;
      SeenList[i] = false;
    }

    // Read edges
    while(1) {
      // End of Case
      if(a == 0 && b == 0) break;

      // Normalize
      a--; b--;

      // Track
      SeenList[a] = SeenList[b] = true;

      // Set
      AdjMatrix[a][b] = 1;

      cin >> a >> b;
    }

    // Floyd-Warshall's APSP
    for (int k = 0; k < MAX; ++k)
      for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j)
          AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j]);

    // Sum up all of the paths
    int edges = 0;
    double sum = 0;
    for (int i = 0; i < MAX; ++i)
      for (int j = 0; j < MAX; ++j) {
        if(i == j) continue;

        // Gee, I really wish they just gave me N
        if(SeenList[i] && SeenList[j]) {
          sum += AdjMatrix[i][j];
          edges++;
        }
      }

    cout << "Case " << ++num_cases << ": average length between pages = ";
    cout << fixed << setprecision(3) << sum/edges << " clicks" << endl;
  }
  return 0;
}