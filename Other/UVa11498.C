/* UVa problem: 11498 Division of Nlogonia
 *
 * Topic: Other
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Given coordinates, determine region.
 *
 * Solution Summary:
 *
 *   Straight forward.
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

using namespace std;

int main() {
  int K, N, M, X, Y;

  while(1) {
    cin >> K;

    if(K == 0) break;

    cin >> N >> M;

    for (int i = 0; i < K; ++i) {
      cin >> X >> Y;

      if      (X == N || Y == M) cout << "divisia" << endl;
      else if (X < N && Y > M)   cout << "NO" << endl;
      else if (X > N && Y > M)   cout << "NE" << endl;
      else if (X > N && Y < M)   cout << "SE" << endl;
      else                       cout << "SO" << endl;

    }
  }

  return 0;
}