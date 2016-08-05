#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>

/*  recursive DFS version using vector */


using namespace std;

vector<bool> visited(26,false);
vector< vector<bool > adjMatrix(26, vector<bool>(26, false));

void dfs(int v) {
  if(visited[v]) return;

  visited[v] = true;

  for(int u = 0; u < adjMatrix.size(); ++u)
    if(adjMatrix[v][u])
      dfs(u);

}

void solve() {

  // vector way
  visited.assign(n, false);
  adjMatrix.assign((n, vector<bool>(26, false));)


  memset(adjMatrix, false, sizeof(adjMatrix));

  char maxLetter;
  string line;
  cin >> maxLetter;
  getline(cin, line);

  int n = maxLetter - 'A' + 1; // num nodes

  /* read in graph */
  // char u,v;
  // while(cin >> u >> v) {
  //   // undireced graph
  //   adjMatrix[u-'A'][v-'A'] = true;
  //   adjMatrix[v-'A'][u-'A'] = true;
  // }

  while(true) {
    getline(cin,line);
    if(line.length() != 2) break; // will eat blank line that fails test
    adjMatrix[line[0]-'A'][line[1]-'A'] = true;
    adjMatrix[line[1]-'A'][line[0]-'A'] = true;
  }

  int components = 0;
  for (int start = 0; start < n; start++) {
    if(visited[start]) continue; // already visisted
    visited[start] = true;

    // new component
    components++;

    dfs(start);  // lost the code here... maybe wrong in this loop

  }

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
