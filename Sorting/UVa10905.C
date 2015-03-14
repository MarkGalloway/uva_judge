/* UVa problem: 10905 Children's Game
 *
 * Topic: Sorting
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Given a sequence of numbers, concatenate them to form the
 *   number with the largest possible value.
 *
 * Solution Summary:
 *
 *   Sorting based on custom comparator
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

using namespace std;

int n;
string A[50];

/*
 *  Sorts based on comparision of concatenations to determine if
 *  string a would make a larger number if it came before b or
 *  vice versa
 */
bool comparator(const string &a, const string &b) {
  if(a + b <= b + a)
    return false;
  return true;
}

int main() {

  while(1) {
    cin >> n;

    // End of cases
    if(n == 0) break;

    // Read in the Ints as Strings (for easy comparison)
    for (int i = 0; i < n; ++i)
      cin >> A[i];

    // Sort based off of comparator
    sort(A, A+n, comparator);

    // Print the result
    for (int i = 0; i < n; ++i)
      cout << A[i];

    // Newline between cases
    cout << endl;

  }
  return 0;
}