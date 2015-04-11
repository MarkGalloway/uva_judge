/* UVa problem: 406 Prime Cuts
 *
 * Topic: Number Theory
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Given numbers N and C, find the prime numbers <= N
 *   Print the range of length 2*C from the middle of range 1..N primes
 *
 * Solution Summary:
 *
 *   Sieve of Eratosthenes to generate primes
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
#include <cassert>

using namespace std;

typedef vector<int> vi;

bitset<1010> bs; //max size of problem
vi primes;


/*
 *  Generate primes between 1 and `upperbound`
 */
void sieve(int upperbound) {
  bs.set();
  bs[0] = 0;

  // 1 is prime for this problem
  primes.push_back(1);

  for (int i = 2; i <= upperbound; ++i) {
    if(bs[i]) {
      // Cross out multiples of i
      for (int j = i*i; j <= upperbound; j+=i) {
        bs[j] = 0;
      }
      primes.push_back(i);
    }
  }
}


/*
 *  Finds the index of largest prime <= N in primes vector
 */
int find_max_primes_index(int n) {
  for (int i = primes.size()-1; i >= 0; --i)
    if(primes[i] <= n) return i;

  assert(0);
  return 0;
}


int main() {
  // Generate primes
  sieve(1000 + 1);

  int n, c;

  while(cin >> n >> c) {
    // Find the max prime between 1 < N
    int size = find_max_primes_index(n) + 1;

    // Length of range to print
    int length = 2*c;
    if(size % 2 != 0) length--;

    // Default: Entire range
    int start = 0, end = size;

    // Shorten range if necessary
    if(size > length) {
      start = (size - length) / 2;
      end = start + length;
    }

    // Print range of primes
    cout <<  n << " " << c << ":";
    for (int i = start; i < end; ++i)
      cout << " " << primes[i];

    // double endl, even on last line => Time waster
    cout << endl << endl;

  }
  return 0;
}