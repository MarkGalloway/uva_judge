#include <iostream>
#include <queue>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

void solve() {

  // Matrix way
  bool adjMatrix[26][26];
  bool visited[26];

  // vector way
  //vector<bool> visited(26,false);
  //vector< vector<bool > adjMatrix(26, vector<bool>(26, false));

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
  queue<int> q;
  for (int start = 0; start < n; start++) {
    if(visited[start]) continue; // already visisted
    visited[start] = true;

    // new component
    components++;

    q.push(start);
    while(!q.empty()) {
      int curr = q.front();
      q.pop();

      //look at neighbors
      for(int next = 0; next < n; next++) {
        if(adjMatrix[curr][next] && !visited[next]) {
          visited[next] = true;
          q.push(next);
        }
      }
    }

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
