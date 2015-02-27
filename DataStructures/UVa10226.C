/* UVa problem: 10226 Hardwood Species
 *
 * Topic: Data structures: heaps, priority queues, etc.
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Keep track of the frequencies of each tree, and then output
 *   in alphabetical order along with the precent of total propulation
 *   of that species of tree
 *
 * Solution Summary:
 *
 *   The textbook hint said to use hashing. I had originally planned
 *   to use a hash of 26 maps, each map would hold the trees based
 *   on the first letter. However, I was getting a RTE so I commented
 *   out the hashing to see if that was the issue and then I got an
 *   AC using just a single map. Basically, I just put the data
 *   into a map and printed the frequencies.
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

#include <iostream> // cout
#include <map> // for map
#include <string> // for string

using namespace std;

typedef map<string,int> species_count;

int main() {

  int cases;
  cin >> cases >> ws;

  while(cases--) {

    species_count sc;
    string species;
    int count = 0;

    // Gobble the blank line before each test case
    cin >> ws;

    while(getline(cin, species)) {
      if(species == "") {
        break; // Start of next test case
      }

      sc[species]++;
      count++;
    }

      species_count::iterator it = sc.begin();

      cout.setf(ios::fixed);
      cout.precision(4);
      for(; it != sc.end(); ++it) {
        cout << (*it).first << " ";
        cout << ((*it).second/(double)count)*100 << endl;
      }

    if(cases > 0)
        cout << endl; // need a space before next output set
  }

  return 0;
}