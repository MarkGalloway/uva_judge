/* UVa problem: 10305 Ordering Tasks
 *
 * Topic: Graph Traversal
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Given N tasks and M dependencies between tasks, print a possible
 *   task order w.r.t dependencies
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
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<bool> vb;

vector<vi> AdjList;
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
  int n, m, a, b;

  while(1) {
    cin >> n >> m;

    // Init
    AdjList.assign(n + 1, vi());
    visited.assign(n + 1, false);
    toposort.clear();

    if(n == 0 && m == 0) break;

    for (int i = 0; i < m; ++i) {
      cin >> a >> b;

      // Add dependency (edge)
      AdjList[a].push_back(b);
    }

    for (int i = 1; i <= n; ++i) {
      if(!visited[i])
        dfs(i);
    }

    vi::reverse_iterator i = toposort.rbegin();
    cout << *i;
    i++;
    for (; i != toposort.rend(); ++i) {
      cout << " " << *i;
    }

    cout << endl;
  }

  return 0;
}