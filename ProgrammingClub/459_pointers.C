/*

  Union Find Data Structure

  Each node points to itself (its own representative)
  Everytime we add an edge we choose one node to be a representative (points to itself). All others point to the representative. this is the connected component and the representative count is the number of connected components

  You shorten the chain of pointers as you go.

  2 ops:
    Find(u) - find representative
    Union(u,v) - merge two components



*/

#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>

/*  recursive DFS version using vector */


using namespace std;

vector<int> unionFind;

int find(int v) {
  if(unionFind[v] == v) return v;

  unionFind[v] = find(unionFind[v]); //redirect to representative

  return unionFind[v];
}

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  unionFind[u] = v;
}

void solve() {
  string line;
  getline(cin, line);

  int n = line[0] - 'A' + 1; // num nodes

  unionFind.resize(n);
  for (int i = 0; i < n; ++i)
    unionFind[i] = i;

  while(true) {
    getline(cin,line);
    if(line.length() != 2) break; // will eat blank line that fails test
    int u = line[0]-'A', v = line[1]-'A';

    if(find(u) != find(v))
      merge(u,v);
  }

  int components = 0;

  // go through and count the representativs
  for (int i = 0; i < n; ++i)
    if(unionFind[i] == i)
      components++;

  cout << components;

}

int main()
{
  int cases;
  cin >> cases >> ws; // ws eats white spaces
  for (int i = 0; i < cases; ++i) {
    solve();
    if(i + 1 < cases) cout << endl;
  }

  return 0;
}
