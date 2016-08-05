/* UVa problem: 10327 Flip Sort
 *
 * Topic: Sorting
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Count the number of inversions
 *
 * Solution Summary:
 *
 *   Use O(n^2) Bubble Sort, a swap is an inversion
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

const int MAX_N = 10001;

int n, list[MAX_N];

int main() {

  while(cin >> n) {
    // Read input
    int temp;
    for (int i = 0; i < n; ++i) {
      cin >> list[i];
    }

    int inversions = 0;

    // Bubble Sort
    for (int i = n; i > 0; --i) {
      for (int j = 1; j < i; ++j) {
        if(list[j-1] > list[j]) {
          // Count inversions
          inversions++;

          // Swap
          temp = list[j-1];
          list[j-1] = list[j];
          list[j] = temp;
        }
      }
    }

    // Print Solution
    cout << "Minimum exchange operations : " << inversions << endl;
  }

  return 0;
}