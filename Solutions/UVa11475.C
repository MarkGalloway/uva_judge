/* UVa problem: 11475 Extend to Palindrome
 *
 * Topic: String (search, manipulation, matching)
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Given a string, print out the shortest (in length) palindrome.
 *
 * Solution Summary:
 *
 *   The idea here is that, in a palindrome, the suffix of the
 *   orginal string and the prefix of the reverse string are
 *   the same, eg/
 *                panamacanalanac
 *                          lanacamanap
 *   By using a modified KMP, we can return the number of characters
 *   of the longest suffix/reverse suffix match when the original
 *   string is exausted. We can then use that number of characters to
 *   index the reverse string and append the end portion to the
 *   original string.
 *
 *
 * Used Resources:
 *
 *   Howard Cheng's Hint
 *      - To use the reverse string in KMP
 *   Competitive Programming 3
 *      - Basic KMP algorithm code provided in textbook.
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */
#include <iostream>

using namespace std;

const int MAX_N =  100001; // max string length as per spec

int b[MAX_N]; // back table

/*
 * Preprocess string P to fill the back table
 */
void kmpPreprocess(const string &P) {
  int i = 0, j = -1, m = P.length();
  b[0] = -1; // starting values

  // pre-process the pattern string P
  while (i < m) {
    while (j >= 0 && P[i] != P[j])
      j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j;
  }
}

/*
 * Modified KMP which returns the length of the final
 * match at the end of the string (could be zero)
 */
int kmpSearch(const string &P, const string &T) {
  int i = 0, j = 0, n = T.length(); // starting values

  while (i < n) { // search through string T
    while (j >= 0 && T[i] != P[j])
      j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    if (i == n) {
      // If we're at the end of T then j is the index where the
      // last match ended (the end of common middle of palindrome).
      return j;
    }
  }
  return 0;
}

int main() {

  string line;
  while(getline(cin, line)) {
    // Reverse the line
    string rev_line(line.rbegin(), line.rend());

    // Perform KMP
    kmpPreprocess(rev_line);
    int index = kmpSearch(rev_line, line);

    // Output result palindrome
    string suffix = rev_line.substr(index, rev_line.length()-1);
    cout << line << suffix << endl;
  }

  return 0;
}