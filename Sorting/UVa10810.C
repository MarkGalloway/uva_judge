/* UVa problem: 10810 Ultra-QuickSort
 *
 * Topic: Sorting
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Sort Numbers in non-decreasing order while counting inversions
 *
 * Solution Summary:
 *
 *   Merge Sort. When mergin from the right partition, the number of
 *   inversions is the size of the left partition.
 *   Pitfall: Took me a while to realize I needed a long long for the
 *   inversion count.
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
#include <vector>

using namespace std;

typedef vector<int> vi;

int N;
long long inversions;

void merge(vi &unsorted, const int L, const int M, const int R) {
  vi sorted;

  int i = L;
  int j = M + 1;

  // Merge sorted sublists
  while (i <= M || j <= R) {
    if(i > M)
      sorted.push_back(unsorted[j++]);
    else if(j > R)
      sorted.push_back(unsorted[i++]);
    else {
      if(unsorted[i] <= unsorted[j])
        sorted.push_back(unsorted[i++]);
      else {
        inversions += M - i + 1;
        sorted.push_back(unsorted[j++]);
      }
    }
  }
    // Copy back to original list
    for (uint i = 0; i < sorted.size(); ++i)
      unsorted[L + i] = sorted[i];
}

void merge_sort(vi &unsorted, const int L, const int R) {
  // Basecase: 0-1 element, sorted sublist
  if(L >= R) {
    return;
  }

  // Recursive Case: Divide into sublists
  int M = (L + R) / 2;
  merge_sort(unsorted, L, M); // Left Half
  merge_sort(unsorted, M + 1, R); // Right half

  // Merge sorted sub-lists
  merge(unsorted, L, M, R);
}

int main() {
  vi unsorted;

  while(cin >> N) {
    // End of Cases
    if(N == 0)
      break;

    // Init
    unsorted.clear();
    inversions = 0;

    // Read unsorted ints
    int temp;
    for (int i = 0; i < N; ++i) {
      cin >> temp;
      unsorted.push_back(temp);
    }

    // Merge Sort
    merge_sort(unsorted, 0, N-1);

    cout << inversions << endl;
  }

  return 0;
}