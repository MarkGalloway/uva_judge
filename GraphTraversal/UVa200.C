/* UVa problem: 200 Rare Order
 *
 * Topic: Graph Traversal
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Given snippes of collating sequences of letters 'A'-'Z',
 *   determine the overall collating sequence.
 *
 * Solution Summary:
 *
 *   Topological sort using DFS
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
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vector<vi> AdjList;
vb SeenList;
vb visited;
vi toposort;

/*
 * Toposort DFS
 */
void dfs(int u) {
  // Mark visited
  visited[u] = true;

  for (int i = 0; i < (int)AdjList[u].size(); ++i) {
    int v =  AdjList[u][i];

    // DFS on children
    if(!visited[v])
      dfs(v);
  }

  // Store toposort
  toposort.push_back(u);
}


int main() {
  // Init
  AdjList.assign(26, vi());
  SeenList.assign(26, false);
  visited.assign(26, false);
  string prev, current;
  cin >> prev;

  if(prev[0] == '#') return 0; // I doubt this is possible

  // Populate SeenList
  for (size_t i = 0; i < prev.length(); ++i)
    SeenList[prev[i] - 'A'] = true;

  while(cin >> current) {
    // End of Cases
    if(current[0] == '#') break;

    // Populate SeenList
    for (size_t i = 0; i < current.length(); ++i)
      SeenList[current[i] - 'A'] = true;

    // Compare the strings for the first difference
    for (size_t i = 0; i < min(prev.length(), current.length()); ++i) {
      // Add edge

      if(prev[i] != current[i]) {
        // cout << "Adding edge: " << prev[i] << "->" << current[i] << endl;
        AdjList[prev[i] - 'A'].push_back(current[i] - 'A');
        break;
      }

    }
    prev = current;
  }

    // Loop through seen nodes in reverse (For default alphabetical order)
    for (int i = 25; i >= 0; --i) {
      // Not seen
      if(SeenList[i] == false) continue;

      // Toposort
      if(!visited[i])
        dfs(i);
    }

    // Print Solution: topological sort
    for (vi::reverse_iterator i = toposort.rbegin(); i != toposort.rend(); ++i) {
      cout << char(*i + 'A');
    }
    cout << endl;


  return 0;
}