/* UVa problem: 10034 Freckles
 *
 * Topic: Graph Algorithms
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Given 2D points (x,y), build a minimum spanning tree
 *
 * Solution Summary:
 *
 *   Create edges between each point where the edge weight is the
 *   distance between the points. Used Kruskal's greedy algorithm of
 *   sorting the EdgeList and adding edges that are both the smallest
 *   and do not add a cycle. Used UnionFind to preform cycle checking,
 *   as presented in the book.
 *
 * Used Resources:
 *
 *   Competitive programming 3 - Source code for UnionFind
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef pair<double,double> dd;
typedef pair<int,int> ii;
typedef pair<double, ii> dii;

vector<dd> points;
vector<dii> EdgeList; // (weight, 2 verticies)


// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {
private:
  vi p, rank, setSize;
  int numSets;

public:
  UnionFind(int N) {
    setSize.assign(N, 1);
    numSets = N;
    rank.assign(N, 0);
    p.assign(N, 0);
    for (int i = 0; i < N; i++) p[i] = i;
  }

  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      numSets--;
      int x = findSet(i), y = findSet(j);
      // rank is used to keep the tree short
      if (rank[x] > rank[y]) {
        p[y] = x;
        setSize[x] += setSize[y];
      }
      else {
        p[x] = y;
        setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }

  int numDisjointSets() { return numSets; }

  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};


/*
 *  Distance between two points
 */
double dist(dd p1, dd p2) {
    double x = p1.first - p2.first;
    double y = p1.second - p2.second;
    return sqrt(x * x + y * y);
}

int main() {
  int cases, n;
  double x, y;
  bool first = true;

  cin >> cases >> ws;

  while(cases--) {
    cin >> ws >> n >> ws;

    // Init
    points.clear();
    EdgeList.clear();

    // Read in the points
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      // cout << x << " " << y << endl;
      // dd p = dd(x, y);
      // cout << p.first << "," << p.second << endl;
      points.push_back(dd(x, y));
    }

    // for (int i = 0; i < n; ++i) {
    //   cout << points[i].first << "," << points[i].second << endl;
    // }

    double weight;
    // Build the Edge List
    for (int u = 0; u < n; ++u) {
      for (int v = 0; v < n; ++v) {
        // cout << "(" << u << ", " << v << ")" << " = ";
        // Is this necessary ???????????????????????
        // if(u == v) continue;

        // Weight is dist(u,v)
        weight = dist(points[u], points[v]);

        // cout << points[u].first << "," << points[u].second << " -> ";
        // cout << points[u].first << "," << points[u].second << " = ";
        // cout << weight << endl;

        // Make (weight, (u,v)) Edge
        EdgeList.push_back(make_pair(weight, ii(u, v)));
      }
    }

    // Sort EdgeList
    sort(EdgeList.begin(), EdgeList.end());

    // cout << EdgeList.size() << endl;

    // Use Union Find to merge disjoint sets
    double cost = 0.0;
    UnionFind UF(n);

    for (size_t i = 0; i < EdgeList.size(); ++i) {
      dii front = EdgeList[i];

      if(!UF.isSameSet(front.second.first, front.second.second)) {
        cost += front.first;
        UF.unionSet(front.second.first, front.second.second);
      }
    }

    // Print unnecessary blank line between cases;
    if(!first) {
      cout << endl;
    } else {
      first = false;
    }

    // Print MST cost
    cout << fixed << setprecision(2) << cost << endl;

  }
  return 0;
}