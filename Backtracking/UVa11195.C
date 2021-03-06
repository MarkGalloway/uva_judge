/* UVa problem: 11195 Another n-Queen Problem
 *
 * Topic: Backtracking
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *    Find the number of placements of n queens on an n*n board so that no two
 *    queens attack each other.
 *    There are some bad squares where queens cannot be placed.
 *
 * Solution Summary:
 *
 *   Recursive backtracking using bitmasks, as presented in the textbook.
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

int board[15];
unsigned int counter;
unsigned int solutions;
int n, OK;


void backtrack(int col, int rw, int ld, int rd) {
  // Base Case: All columns are full
  if(rw == OK) {
    ++solutions;
  }
  // Recursive Case: Try the next column
  else {
    // Find the available rows
    int pos = OK & (~(rw | rd | ld | board[col]));

    while(pos) {
      int p = pos & -pos; // Find the Least Significant Bit (The next row)
      pos -= p;           // Remove the Least Significant Bit (The Row)
      // Recurse using this column as our choice
      backtrack(col + 1, (rw | p), (ld | p) << 1, (rd | p) >> 1);

    }
  }
}

int main() {

  counter = 0;

  while(1) {
    cin >> n;

    // End of input
    if(n == 0) break;

    // Initialize
    solutions = 0;
    OK = (1 << n) - 1;
    for (int i = 0; i < 15; ++i)
      board[i] = 0;
    char c;

    // Read in the "Bad Cells" for this board
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> c >> ws;
        if(c == '*')
          // row i is a "Bad Cell" of column j
          board[j] = board[j] | (1 << i);
      }
    }

    // Recursively backtrack solution
    backtrack(0,0,0,0);

    // Print Solution
    cout << "Case " << ++counter << ": " << solutions << endl;
  }

  return 0;
}