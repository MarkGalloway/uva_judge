/* UVa problem: 567 Risk
 *
 * Topic: Graph Algorithms
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Given 19 cities with neighbour information, determine shortest
 *   routes of attack from 1 city to another
 *
 * Solution Summary:
 *
 *   Floyd-Warshall's APSP
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
#include <iomanip>

using namespace std;

const int INF = 1000000000;
const int MAX = 21;

int main() {
  int cases = 0, n, u, v, AdjMatrix[MAX][MAX];

  while(1) {

    // Init
    for (int i = 0; i < MAX; ++i) {
      for (int j = 0; j < MAX; ++j)
        AdjMatrix[i][j] = INF;
      AdjMatrix[i][i] = 0;
    }

    // Read in the 19 countries
    for (int i = 1; i <= 19; ++i) {
      if(!(cin >> n)) goto END; // End of cases

      // Read in each countries neighbours
      for (int j = 1; j <= n; ++j) {
        cin >> u;
        AdjMatrix[i][u] = AdjMatrix[u][i] = 1;
      }
    }

    // Floyd-Warshall's APSP
    for (int k = 0; k < MAX; ++k)
      for (int i = 0; i < MAX; ++i)
        for (int j = 0; j < MAX; ++j)
          AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j]);


    // Newlines between cases
    if(cases > 0) cout << endl;

    // Process the path queries
    cin >> n;
    cout << "Test Set #" << ++cases << endl;

    for (int i = 0; i < n; ++i) {
      cin >> u >> v;
      // Fun with formatting
      cout << setw(2) << u << " to " << setw(2) << v << ": ";
      cout << AdjMatrix[u][v] << endl;
    }

  }

  END:
  return 0;
}