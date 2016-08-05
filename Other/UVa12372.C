/* UVa problem: 12372 Packing For Holiday
 *
 * Topic: Other
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Given dimensions LxWxH, determine if it will fit into Mr.Beans
 *   suitcase.
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

  int cases, l, w, h, n = 0;
  cin >> cases;

  while(cases--) {
    cin >> l >> w >> h;

    cout << "Case " << ++n << ": ";

    if(l > 20 || w > 20 || h > 20) cout << "bad" << endl;
    else cout << "good" << endl;

  }

  return 0;
}