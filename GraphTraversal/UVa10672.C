/* UVa problem: 10672 Marbles On A Tree
 *
 * Topic: Graph Traversal
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   There are N nodes in a tree. There are N marbles distributed
 *   unequally across the nodes. Find the least amount of moves
 *   needed to balance the tree (1 marble at each node).
 *
 * Solution Summary:
 *
 *   I chose to follow Howard Cheng's hint of using DFS. After
 *   drawing a few diagrams it was obvious that if you balance
 *   a node while leaving it by borrowing or giving to the parent
 *   node (regardless of debt) then the entire tree will balance and
 *   the optimal number of steps will be revealed by recording the
 *   borrowing/giving counts with each parent.
 *
 *   The data structures used were an Adjacency List to record
 *   edge information (vector of vector<int>), and then just
 *   simple vectors to store bookkeeping information such as
 *   a visited status, parent node, and node marble count.
 *
 * Used Resources:
 *
 *   1. Howard Cheng's Hint:www.cs.uleth.ca/~cheng/contest/hints.html
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

vector<vi> AdjList; // Adjacency List
vi MarbleCounts;
vi ParentList; // List of Parents
vector<bool> SeenList; // seen list

/*
 * Recursively DFS the graph, balancing a nodes
 * marbles (giving or taking) from the parent node
 * upon leaving each node such that the node being left
 * and all of its children will have exactly 1 marble.
 * Returns the number of moves needed to balance the current
 * subtree.
 */
int dfs_distribute_marbles(int vertex) {
  SeenList[vertex] = true;

  // Recurse Children
  int child_moves = 0;
  for (int i = 0; i < (int)AdjList[vertex].size(); ++i)
    if(!SeenList[AdjList[vertex][i]]) {
      // Record Parent
      ParentList[AdjList[vertex][i]] = vertex;
      // Get Child Moves
      child_moves += dfs_distribute_marbles(AdjList[vertex][i]);
    }

  // Balance this nodes marbles
  int my_marbles = MarbleCounts[vertex];
  int moves = 0;
  if(my_marbles != 1)
    moves = (1 - my_marbles) * -1;

  // Adjust marbles with parent
  MarbleCounts[ParentList[vertex]] += moves;
  MarbleCounts[vertex] = 1;

  return abs(moves) + child_moves;
}

int main() {

  while (1) {
    int nodes;
    cin >> nodes;

    if(nodes == 0) break; // End of cases

    AdjList.assign(nodes+1, vi());
    MarbleCounts.assign(nodes+1, int());
    ParentList.assign(nodes+1, int());
    SeenList.assign(nodes+1, false);

    // Read in graph data for this case
    for (int i = 1; i <= nodes; ++i) {
      int vertex, marbles, children;
      cin >> vertex >> marbles >> children;

      MarbleCounts[vertex] = marbles;

      for (int j = 1; j <= children; ++j) {
        int child;
        cin >> child;
        AdjList[vertex].push_back(child);
        AdjList[child].push_back(vertex);
      }
    }

    // DFS the graph to get the number of marble moves
    int moves = dfs_distribute_marbles(1);

    // Print Result For Case
    cout << moves << endl;

  }

  return 0;
}