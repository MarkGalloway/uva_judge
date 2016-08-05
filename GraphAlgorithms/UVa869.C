/* UVa problem: 869 Airline Comparison
 *
 * Topic: Graph Algorithms
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Given the catalogs of two airline companies,
 *   determine if they are equivalent or not.
 *
 * Solution Summary:
 *
 *   Run Warshall's algorithm on both Adjacency Matrices and then
 *   compare for differences
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

int first [26][26];
int second[26][26];

int main() {
  int cases, n, m;
  bool newline = false;
  cin >> cases >> ws;

  while (cases--) {

    // Spaces between cases... fun times
    if(newline) cout << endl;
    else newline = true;

    // Init
    char a, b;
    memset(first, 0, sizeof first);
    memset(second, 0, sizeof second);

    // Read in 1st airline AdjMatrix
    cin >> ws >> n >> ws;
    for (int i = 0; i < n; ++i) {
      cin >> a >> b >> ws;
      first[a-'A'][b-'A'] = 1;
    }

    // Read in 2nd airline AdjMatrix
    cin >> ws >> m >> ws;
    for (int i = 0; i < m; ++i) {
      cin >> ws >> a >> ws >> b >> ws;
      second[a-'A'][b-'A'] = 1;
    }

    // Warshall's Alg on first airline AdjMatrix
    for (int k = 0; k < 26; ++k)
      for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
          first[i][j] |= (first[i][k] & first[k][j]);

    // Warshall's Alg on second airline AdjMatrix
    for (int k = 0; k < 26; ++k)
      for (int i = 0; i < 26; ++i)
        for (int j = 0; j < 26; ++j)
          second[i][j] |= (second[i][k] & second[k][j]);


    for (int i = 0; i < 26; ++i)
      for (int j = 0; j < 26; ++j)
        if(first[i][j] != second[i][j]) {
          // HTTP 400: Flight difference detected. Abort.
          cout << "NO";
          goto END;
        }

    // Both Airlines fly to all the same cites. How environmentally friendly.
    cout << "YES";

    END:
    cout << endl;

  }
  return 0;
}