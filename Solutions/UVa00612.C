/* UVa problem: 00612 DNA Sorting
 *
 * Topic: Sorting
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Sort DNA strings based on 'level of sortedness', but preserving input
 *   ordering for pairs with the same 'level of sortedness'
 *
 * Solution Summary:
 *
 *   Inversion counting using O(n^2) bubble sort
 *   Sorting of Inversions using O(n^2) std:stable_sort
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
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair <int,string> is;
typedef vector<is> vis;


/*
 * Bubble sort which counts and returns the inverson count
 */
int inversion_counting_bubblesort(string s) {
  int inversions = 0;

  for (int i = s.length(); i > 0; --i) {
    for (int j = 1; j < i ; ++j) {
      if(s[j-1] > s[j])
        inversions++;

        // Swap
        char temp = s[j-1];
        s[j-1] = s[j];
        s[j] = temp;
    }
  }
  return inversions;
}


/*
 *  Compares two (inversion, line) pairs based on the
 *  inversion
 */
bool comparator(is a, is b) {
  if(a.first >= b.first)
    return false;

  return true;
}


int main() {

  int cases;
  cin >> cases;

  while (cases--) {
    vis data;
    int length, lines;
    cin >> ws >> length >> lines >> ws;

    // Read the lines
    string line;
    for (int i = 0; i < lines; ++i) {
      getline(cin, line);
      // Store the (inversion, line) pair
      data.push_back(is(inversion_counting_bubblesort(line), line));
    }

    // Stable sort the (inversion, line) pairs
    stable_sort(data.begin(), data.end(), comparator);

    // print the answer
    for (std::vector<is>::iterator i = data.begin(); i != data.end(); ++i)
      cout << (*i).second << endl;

    // Blank line between cases
    if(cases > 0) cout << endl;

  }

  return 0;
}