/* UVa problem: 10655 Contemplation! Algebra
 *
 * Topic: Arithmetic
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   given p = a + b, q = ab, and n: find a^n + b^n
 *
 * Solution Summary:
 *
 *   implementation of the Matrix Power solution as
 *   discussed in section 9.21 of the textbook, where:
 *    a^n + b^n == [p -q 1 0]^n * [p 2]
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

typedef long long ll;

const int MAX_N = 2;

struct Matrix {
  ll mat[MAX_N][MAX_N];
};


/*
 *  Multipy two matrices, A and B
 */
Matrix matMul(Matrix a, Matrix b) {
  Matrix ans;
  int k;

  for (int i = 0; i < MAX_N; i++)
    for (int j = 0; j < MAX_N; j++)
      for (ans.mat[i][j] = k = 0; k < MAX_N; k++)
        ans.mat[i][j] += a.mat[i][k] * b.mat[k][j];

  return ans;
}


/*
 *  Raise matrix to power p
 */
Matrix matPow(Matrix base, int p) {
  // Prepare identity matrix
  Matrix ans;
  for (int i = 0; i < MAX_N; i++)
    for (int j = 0; j < MAX_N; j++)
      ans.mat[i][j] = (i == j);

  while (p) {
    // Check if p is odd (the last bit is on)
    if (p & 1)
      ans = matMul(ans, base);
    // Square the base
    base = matMul(base, base);
    // Divide p by 2
    p >>= 1;
  }
  return ans;
}


int main() {
  int p, q, n;

  while(cin >> p >> q >> n) {

    // Create Matrix [p -q 1 0]
    Matrix ans;
    ans.mat[0][0] = p;
    ans.mat[0][1] = -q;
    ans.mat[1][0] = 1;
    ans.mat[1][1] = 0;

    // Raise matrix [p -q 1 0] to the power of N
    ans = matPow(ans, n);

    // Multiply bottom row of ans by [p 2]
    ll solution = ans.mat[1][0] * p + ans.mat[1][1] * 2;

    // Print Answer
    cout << solution << endl;

  }

  return 0;
}