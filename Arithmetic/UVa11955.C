/* UVa problem: 11955 Bionomial Theorem
 *
 * Topic: Arithmetic
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Expand a given power of a sum into a sum of powers.
 *
 * Solution Summary:
 *
 *   Binomial Coefficient(C(n,k)) formula, Dynamic Programming
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
#include <cstring>

using namespace std;

long long memo[51][51];

long long binomial_coefficient(int n, int k) {
  // Base Cases
  if(k == 0) return 1;
  if(n == k) return 1;

  // Already Calculated
  if(memo[n][k] != -1) return memo[n][k];

  // Recursive Case
  return memo[n][k] = binomial_coefficient(n-1, k-1) +
                      binomial_coefficient(n-1, k);
}


int main() {

  int cases, tc = 0;

  cin >> cases;

  while(cases--) {

    // Init
    memset(memo, -1, sizeof memo);

    int exponent;
    char c;
    string A, B;

    // Read the Input
    cin >> c; // Grab+discard the opening brace
    cin >> c;
    while(c != '+') {
      A += c;
      cin >> c;
    }

    cin >> c;
    while(c != ')') {
      B += c;
      cin >> c;
    }

    cin >> c; // Grab+discard the power
    cin >> exponent;

    // Print Answer
    cout << "Case " << ++tc << ": ";
    for (int i = 0; i <= exponent; ++i) {
      long long coef = binomial_coefficient(exponent, i);

      int x = exponent - i;
      int y = i;

      // Print Coefficient
      if(coef != 1) cout << coef << "*";

      // Print A
      if(x > 0) {
        cout << A;
        if(x > 1) cout << "^" << x;

        if(y > 0) cout << "*";
      }

      // Print B
      if(y > 0) {
        cout << B;

        if(y > 1) cout << "^" << y;
      }

      // Print joiner
      if(i != exponent) cout << "+";

    }

    cout << endl;
  }

  return 0;
}