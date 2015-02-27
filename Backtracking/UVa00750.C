#include <iostream>
#include <array>
#include <bitset>

using namespace std;

array<int, 14> row;
bitset<30> rw, ld, rd;
int counter;
int n, a, b;


/*
 * Check if a queen can be placed in this (r,c) position
 * by ensuring no other queen is placed on this row or along this
 * diagonal
 */
bool isSafe(int r, int c) {
  return !rw[r] && !rw[r] && !ld[r - c + n - 1] && !rd[r + c];
}

/*
 *  Place Queen at this position and mark rows and diagonals
 *  as occupied
 */
void placeQueen(int r, int c) {
  rw[r] = ld[r - c + n - 1] = rd[r + c] = true;
  row[c] = r;
}

/*
 *  Remove Queen at this position and mark rows and diagonals
 *  as free
 */
void removeQueen(int r, int c) {
  rw[r] = ld[r - c + n - 1] = rd[r + c] = false;
  row[c] = 0;
}

/*
 * Recursively place all queens onto the 8,8 board.
 */
void backtrack(int c) {
  // Base Case: All columns are full
  if(c == n) {
    // Print the solution
    cout.width(2);
    cout << ++counter << "      ";
    for (int i = 0; i < n-1; ++i) {
      cout << row[i] + 1 << " ";
    }
    cout << row[7] + 1 << endl;
  }
  // Recursive Case: Place a queen in this column and recurse.
  if(c == b) {
    // Special Case: Queen must be in this (row,col)
    if(isSafe(a,b)) {
      placeQueen(a,c);
      backtrack(c+1); // Onto the next column
      removeQueen(a,c); // We backtracked to find another solution
    }
  }
  else {
    // Normal Case: Try queen in each safe row and recurse.
    for (int r = 0; r < n; ++r) {
      if(isSafe(r, c)) {
        placeQueen(r,c);
        backtrack(c+1); // Onto the next column
        removeQueen(r,c); // We backtracked to find another solution
      }
    }
  }
}


int main() {
  int cases;
  cin >> cases;

  while(cases--) {
    // Gobble blank line
    cin >> ws;

    // Init
    row = {{}};
    rw = {};
    ld = {};
    rd = {};
    counter = 0;
    n = 8;

    // Read position and normalize
    cin >> a >> b ;
    a--; b--;

    // Print solution header
    cout << "SOLN       COLUMN" << endl;
    cout << " #      1 2 3 4 5 6 7 8" << endl;
    cout << endl;

    // Recursively backtrack solution
    backtrack(0);

    // Blank line between cases
    if(cases)
      cout << endl;
  }

  return 0;
}