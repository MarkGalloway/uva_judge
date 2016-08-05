/* UVa problem: 374 Big Mod
 *
 * Topic: Number Theory
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   given b, p, m, compute b^p mod m
 *
 * Solution Summary:
 *
 *   I modified the recursive fast exponentiation algorithm presented in
 *   the textbook section 9.21 to use modulo
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

/*
 * computes base^p mod p recursively.
 */
int modPow(int base, int p, int m) { // O(log p)
  if      (p == 0) return 1;
  else if (p == 1) return base;
  else {
    int res = modPow(base, p / 2, m);
    res = (res * res) % m;
    if (p % 2 == 1)
      res = (res * base) % m;
    return res;
  }
}

int main() {
  int b, p, m;

  while(cin >> b) {
    cin >> p >> m >> ws;

    // cout << b << " " << p << " " << m << endl;
    cout << modPow(b%m,p,m) << endl;

  }


  return 0;
}