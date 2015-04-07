/* UVa problem: 10223 How many nodes ?
 *
 * Topic: Combinatorics
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Given a catalan number Cat(n), print n
 *
 * Solution Summary:
 *
 *   Precompute calatan numbers < Cat(20) and use reverse index
 *
 * Used Resources:
 *
 *   Competitive Programming 3
 *   Problem recommended by Tamara Bain as "Super easy"
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream>
#include <cstring>
#include <map>

using namespace std;

typedef long long ll;

ll memo[51][51];
map<ll,int> rev_index;


ll binomial_coefficient(ll n, ll k) {
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

  // Init
  memset(memo, -1, sizeof memo);

  // Precompute Catalan Numbers < 20, store in reverse index
  for (int i = 1; i < 20; ++i) {
    ll catalan = binomial_coefficient(2*i, i) / (i+1);
    rev_index[catalan] = i;
  }

  ll n;
  while(cin >> n) {
    // Lookup and print solution
    cout << rev_index[n] << endl;
  }

  return 0;
}