/* 11324 - The Largest Clique
 * find the largest set of verticies such that there is a path from one to another in the set
 */
#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > g, rev_g, comp_g;  // Adjacency List
vector<int> finish, compNum, comp_weight, mwp;
vecor<bool> seen;
int counter;

void dfs_finish_time(int v) {
  seen[v] = true;
  for (int i = 0; i < g[v].size(); ++i) {
    if(!seen[g[v][j]])
      dfs_finish_time(g[v][j]);

  finish[counter] = v;
  ++counter;
  }
}

void dfs_comp_num(int v) {
  compNum[v] = counter;
  for (int i = 0; i < rev_g[v].size(); ++i) {
    if(compNum[rev_g[v][j] == -1)
       dfs_comp_num(rev_g[v][j]);

  finish[v] = component;
}

int dfs_mwp(int v) {
  if(mwp[v] != -1) return mwp[v];

  mwp[v] = 0;
}

int main() {

  int t;
  cin >> t;

  while(t--) {
    int n, m;
    cin >> n >> m;

    g.assign(n, vector<int>(0));
    rev_g.assign(n, vector<int>(0));
    finish.assign(n, -1);
    seen.assign(n, false);

    while(m--) {
      int u, v;
      cin >> u >> v;

      g[u-1].push_back(v-1);
      rev_g[v-1].push_back(u-1);
    }

    // dfs to get finishing times
    counter = 0;
    for (int i = 0; i < n; ++i) {
      if(!seen[i])
        dfs_finish_time(i);
    }

    // second dfs to number the components
    counter = 0;
    compNum.assign(n,-1);
    for (int i = n-1; i >= 0; --i) {
      if(compNum[finish[i]] != -1) continue;

      dfs_comp_num(finish[i]);
      counter++;
    }

    // build connected component graph
    comp_g.assign(counter, vector<int>(0));
    comp_weight(counter,0);
    for (int i = 0; i < n; ++i) {
       ++comp_weight[compNum[i]];
       for (int j = 0; j < g[i].size(); ++j) {
          if(compNUm[i] != compNum[g[i][j]])
            comp_g[compNUm[i]].push_back(compNum[g[i][j]]);
       }
    }


    // find max-weight path in the component graph




  }

  return 0;
}