/* UVa problem: 00193 Graph Coloring
 *
 * Topic: Backtracking
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Print the optimal bi-coloring of a graph (Find the
 *   Maximal Independent Set).
 *
 * Solution Summary:
 *
 *   Recursive Backtracking to find the Maximal Independent Set.
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
#include <bitset>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef bitset<100> bs;


vector<bs> adjMatrix;
bs solution, current, used;
int n;

/*
 * Backtack through all unused nodes, adding their
 * neighbors to the used set each call such that
 * we find the maximal independent set
 */
void backtrack(int i, bitset<100> used) {

  // Base Case, we have explored all nodes
  if(used.count() == n) {
    if(current.count() >= solution.count()) {
      // We found a bigger Independent Set.
      solution = current;

    }
  }
  // Recursive Case, keep exploring
  for (int j = i; j < n; ++j) {
    if(!used[j]) {
      current[j] = 1;
      backtrack(j+1, used | adjMatrix[j]);
      current[j] = 0;
    }
  }
}

int main() {

  int cases;
  cin >> cases >> ws;

  while(cases--) {
    int k;
    cin >> n >> k >> ws;
    solution.reset();
    current.reset();
    used.reset();
    adjMatrix.assign(n, bs());

    int a,b;
    for (int i = 0; i < k; ++i) {
      cin >> a >> b >> ws;
      // Normalize
      --a; --b;
      adjMatrix[a][b] = adjMatrix[b][a] = 1;
    }

    for (int i = 0; i < n; ++i) {
      adjMatrix[i][i] = 1;
    }

    // Find Maximal Independent Set
    backtrack(0, used);

    // Print Solution
    cout << solution.count() << endl;
    size_t count = 0;
    for (int i = 0; i < n; ++i) {
      if(solution[i]) {
        ++count;
        if(count == solution.count())
          cout << i+1;
        else
          cout << i+1 << " ";
      }
    }
    cout << endl;
  }

  return 0;
}