/* UVa problem: 1266 Magic Square
 *
 * Topic: Other
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Given an odd number N, form a N*N magic square
 *
 * Solution Summary:
 *
 *   Siamese (De la Loub`ere) method for constructing magic squares as
 *   presented in the book.
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
#include <iomanip>
#include <cstring>

using namespace std;

int N, M[16][16];

/*
 * Creates a magic square using the Siamese method
 */
void magic_square() {

  int value = 0, row, col, new_row, new_col;
  int max = N*N;

  // Place the first
  row = 0;
  col = (N-1)/2;
  M[row][col] = ++value;

  while(value < max) {
    // Move northeast and wrap around
    new_row = (row - 1 + N) % N;
    new_col = (col + 1) % N;

    if(M[new_row][new_col] != 0) {
      // Northeast is taken, move down
      row = (row + 1) % N;
    }
    else {
      // The cell is free
      row = new_row;
      col = new_col;
    }

    // Enter the value
    M[row][col] = ++value;
  }

  return;
}

int main() {

  bool first = true;

  while(cin >> N) {

    // Newline between cases
    if(first) first=false;
    else cout << endl;

    // Init
    memset(M, 0, sizeof M);

    // Build the magic square
    magic_square();

    // Determine the sum
    int sum = 0;
    for (int i = 0; i < N; ++i) {
      sum += M[0][i];
    }

    // Determine print width
    int width;
    if(N*N < 10)
      width = 2;
    else if (N*N < 100)
      width = 3;
    else if (N*N < 1000)
      width = 4;


    // Print Solution Header
    cout << "n=" << N;
    cout << ", sum=" << sum << endl;

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        cout << setw(width) << M[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}