/* UVa problem: 12442 Forwarding Emails
 *
 * Topic: Graph Traversal
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Find the longest path length in a cyclic graph
 *
 * Solution Summary:
 *
 *   Simple DFS modification to recurse until cylce encountered
 *   (a visited node) counting length of path (number of unvisited children)
 *   Had to store results of child calculations to avoid TLE
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
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vi graph;   // Single Column Adjacency List
vi length;  // Path Length
vb visited; // Visited

/*
 *  Modified DFS to recurse until a cycle is
 *  detected, counting path length(each unvisited neighbor)
 */
int dfs(int u) {
  // Mark visited
  visited[u] = true;

  int neighbour = graph[u];

  // Base Case: We have encountered a cycle
  if(visited[neighbour]) return 0;

  // Recursive Case: Traverse neighbor &&
  // Save children length so not recalculated often
  return length[u] = 1 + dfs(neighbour);
}


int main() {

  int num = 0, cases;
  cin >> cases >> ws;

  while(num < cases) {
    int n;
    cin >> n >> ws;

    // Init
    graph.assign(n + 1, int());
    length.assign(n + 1, -1);

    // Read in edges
    int a, b;
    for (int i = 1; i <= n; ++i) {
      cin >> a >> b >> ws;
      graph[a] = b;
    }

    int max = -1, max_index = -1;
    for (int i = 1; i <= n; ++i) {
      if(length[i] == -1) {
        // Reset visited list
        visited.assign(n + 1, false);

        // Calculate path length of i & children
        length[i] = dfs(i);

        // New largest path length
        if(length[i] > max) {
          max_index = i;
          max = length[i];
        }
      }
    }

    // Print solution
    cout << "Case " << ++num << ": " << max_index << endl;
  }
  return 0;
}