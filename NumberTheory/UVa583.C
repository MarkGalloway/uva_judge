/* UVa problem: 583 Prime Factors
 *
 * Topic: Number Theory
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Print all Prime Factors of a number N
 *
 * Solution Summary:
 *
 *   Sieve of Eratosthenes to generate primes
 *   Find Prime Factors using method shown in textbook
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

#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;

bitset<1000010> bs;
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

vi primeFactors(ll N) {
  vi factors;
  ll PF_idx = 0;
  ll PF = primes[PF_idx];

  while(N != 1 && (PF * PF <= N)) {
    while(N % PF == 0) {
      N /= PF;
      factors.push_back(PF);
    }
    PF = primes[++PF_idx];
  }
  if (N != 1) factors.push_back(N);

  return factors;
}


int main() {

  // Generate prime numbers
  sieve(1000000 + 1);

  int n;

  while(1) {
    cin >> n;

    // End of Cases
    if(n == 0) break;

    // Print N =
    cout << n << " = ";

    // If N < 0, print -1 x
    if(n < 0) {
      cout << "-1 x ";
      n *= -1;
    }

    // Calculate prime factors
    vi factors = primeFactors(n);

    // Print prime factors
    vi::iterator i = factors.begin();
    cout << *i;
    ++i;
    for (; i != factors.end(); ++i)
      cout << " x " << *i;

    cout << endl;

  }

  return 0;
}