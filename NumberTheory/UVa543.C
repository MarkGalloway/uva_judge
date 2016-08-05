/* UVa problem: 543 Goldbach's Conjecture
 *
 * Topic: Number Theory
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Find two primes A,B such that n = A + B
 *   where B-A is maximized
 *
 * Solution Summary:
 *
 *   Sieve of Eratosthenes to generate primes
 *   Find smalled prime A where B is also a prime (search)
 *
 * Used Resources:
 *
 *   Competitive Programming 3
 *   Howard Cheng's Hint
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

bitset<1000010> bs; // 10^6 max size of problem
vi primes;

/*
 *  Generate primes between 1 and `upperbound`
 */
void sieve(ll upperbound) {
  bs.set();
  bs[0] = bs[1] = 0;

  for (ll i = 2; i <= upperbound; ++i) {
    if(bs[i]) {
      // Cross out multiples of i
      for (ll j = i*i; j <= upperbound; j+=i) {
        bs[j] = 0;
      }
      primes.push_back((int)i);
    }
  }
}


/*
 *  O(1) prime testing
 */
bool isPrime(int n) {
  return bs[n];
}

/*
 * Performs a search for two primes A,B such that
 *  n = A + B
 *  where B-A is maximized
 */
void solve(int n) {

  for (size_t i = 0; i < primes.size(); ++i) {

    int lower = primes[i];
    int upper = n - lower;

    if(isPrime(upper)) {
      cout << n << " = " << lower << " + " << upper << endl;
      return;
    }
  }

  // No solution found: This should never happen
  cout << "Goldbach's conjecture is wrong." << endl;
}

int main() {

  // Generate prime numbers
  sieve(1000000 + 1);

  int n;

  while(1) {
    cin >> n >> ws;

    // End of cases
    if(n == 0) break;

    // Search for primes
    solve(n);
  }

  return 0;
}