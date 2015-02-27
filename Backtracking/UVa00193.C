#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

typedef vector<bool> vb;
typedef vector<int> vi;
typedef bitset<100> bs;


vector<bs> adjMatrix;
bs solution, current, used;
int n;

void backtrack(int i, bitset<100> used) {

  // Base Case, we have explored all nodes
  if(used.count() == n) {
    if(current.count() >= solution.count()) {
      // We found a bigger Independent Set.
      solution = current;

    }
  }
  // Recursive Case, keep exploring
  for (int j = i; j < n; ++j) {
    if(!used[j]) {
      current[j] = 1;
      backtrack(j+1, used | adjMatrix[j]);
      current[j] = 0;
    }
  }
}

int main() {

  int cases;
  cin >> cases >> ws;

  while(cases--) {
    int k;
    cin >> n >> k >> ws;
    solution.reset();
    current.reset();
    used.reset();
    adjMatrix.assign(n, bs());

    int a,b;
    for (int i = 0; i < k; ++i) {
      cin >> a >> b >> ws;
      // Normalize
      --a; --b;
      adjMatrix[a][b] = adjMatrix[b][a] = 1;
    }

    for (int i = 0; i < n; ++i) {
      adjMatrix[i][i] = 1;
    }

    backtrack(0, used);


    // Print Solution
    cout << solution.count() << endl;
    size_t count = 0;
    for (int i = 0; i < n; ++i) {
      if(solution[i]) {
        ++count;
        if(count == solution.count())
          cout << i+1;
        else
          cout << i+1 << " ";
      }
    }
    cout << endl;


  }

  return 0;
}