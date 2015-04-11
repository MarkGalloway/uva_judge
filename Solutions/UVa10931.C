/* UVa problem: 10931 Parity
 *
 * Topic: Arithmetic
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Calculate the Parity of an integers binary representation
 *
 * Solution Summary:
 *
 *   Used Bitset to count the bits
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
#include <bitset>
#include <string>

using namespace std;

int main() {
  int n;

  while(1) {
    cin >> n;

    // End of Cases
    if(n == 0) break;

    // Convert to bits
    bitset<32> bits(n);

    // To string repr
    string bit_str = bits.to_string();

    // Get substr index
    int start = bit_str.find("1");

    // Print solution
    cout << "The parity of " << bit_str.substr(start);

    cout << " is " << bits.count() << " (mod 2)." << endl;
  }

  return 0;
}