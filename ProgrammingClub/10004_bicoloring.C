#include <iostream>
#include <vector>

using namespace std;


vector< vector<int> > graph;
vector<int> color;

bool dfs(int v, int c) {
  if(color[v]) return color[v] == c; // already colored, contradiction?

  color[v] = c;

  for (int i = 0; i < graph[v].size() ; ++i)
    if(!dfs(graph[v][i], -c))
      return false;

  return true;
}


int main() {


  while(true) {
    int n,m;
    cin >> n;
    if(!n) break;

    cin >> m;

    graph.assign(n, vector<int>()); // will wipe empty
    color.assign(n,0);



    while(m--) {
      int u,v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);


    }


    if(dfs(v,0)) cout << "BICOLORABLE" << endl; // start node ???
    else cout << "NOT BICOLORABLE" << endl;

  }
  return 0;
}
