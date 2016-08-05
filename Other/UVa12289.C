/* UVa problem: 12289 One-Two-Three
 *
 * Topic: Other
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Perform string parsing and print the integer representation
 *
 * Solution Summary:
 *
 *   Straight-Forward
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

int main() {
  int n;
  string s;

  cin >> n;

  while(n--) {
    cin >> s;



    int error = 0;
    if(s[0] != 't') error++;
    if(s[1] != 'w') error++;
    if(s[2] != 'o') error++;

    if(s.length() == 5) cout << "3" << endl;
    else if(error > 1)  cout << "1" << endl;
    else                cout << "2" << endl;

  }

  return 0;
}