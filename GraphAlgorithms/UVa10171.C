/* UVa problem: 10171 Meeting Prof. Miguel...
 *
 * Topic: Graph Algorithms
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Given streets, connectivity, and weight information, determine
 *   the place which is most suitable to meet (minimum energy travel cost)
 *
 * Solution Summary:
 *
 *   Floyd-Warshall's APSP, find minimum(s)
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

const int INF = 1000000000;
const int MAX = 27;

vi places;

int main() {
  int n, energy, AdjMatrixY[MAX][MAX], AdjMatrixM[MAX][MAX];
  char street, direction, x, y, a, b;

  while(1) {

    cin >> n;

    // End of Cases
    if(n == 0) break;

    // Init
    for (int i = 0; i < MAX; ++i) {
      for (int j = 0; j < MAX; ++j) {
        AdjMatrixY[i][j] = INF;
        AdjMatrixM[i][j] = INF;
      }
      AdjMatrixY[i][i] = 0;
      AdjMatrixM[i][i] = 0;
    }

    // Read in the stree info
    for (int i = 0; i < n; ++i) {
      cin >> street >> direction >> x >> y >> energy;

      if(street == 'Y') {
        AdjMatrixY[x-'A'][y-'A'] = min(AdjMatrixY[x-'A'][y-'A'], energy);
        if(direction == 'B')
          AdjMatrixY[y-'A'][x-'A'] = min(AdjMatrixY[y-'A'][x-'A'], energy);
      } else {
        AdjMatrixM[x-'A'][y-'A'] = min(AdjMatrixM[x-'A'][y-'A'], energy);
        if(direction == 'B')
          AdjMatrixM[y-'A'][x-'A'] = min(AdjMatrixM[y-'A'][x-'A'], energy);
      }
    }

    // Floyd-Warshall's APSP
      for (int k = 0; k < MAX; ++k)
        for (int i = 0; i < MAX; ++i)
          for (int j = 0; j < MAX; ++j) {
            AdjMatrixY[i][j] = min(AdjMatrixY[i][j], AdjMatrixY[i][k] + AdjMatrixY[k][j]);
            AdjMatrixM[i][j] = min(AdjMatrixM[i][j], AdjMatrixM[i][k] + AdjMatrixM[k][j]);
          }


    // Location of A and B
    cin >> a >> b;
    int min = INF;
    places.clear();

    // Build the minimum energy paths
    for (int i = 0; i < 26; ++i) {
      int current = AdjMatrixY[a-'A'][i] + AdjMatrixM[b-'A'][i];

      if(current <= min) {
        places.push_back(i);

        if(current < min) {
          min = current;
          places.clear();
          places.push_back(i);
        }
      }
    }

    // Sort
    sort(places.begin(), places.end());

    if(min != INF) {
      cout << min;
      for (vi::iterator i = places.begin(); i != places.end(); ++i) {
        cout << " " << char(*i + 'A');
      }
    }
    else
      cout << "You will never meet.";

    cout << endl;
  }

  return 0;
}