/* UVa problem: 10374 Election
 *
 * Topic: String (search, manipulation, matching)
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   There are a number of candidates with parties. Count the votes for each
 *   candidate and then print the winning party if there is no tie. Reject
 *   votes for unknowen candidates.
 *
 * Solution Summary:
 *
 *   I used a map<string,int> to count the frequency of each candidates vote
 *   and a map<string,string> to map the candidate to his/her party.
 *
 * Used Resources:
 *
 *  - Competitive Programming 3
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

typedef map<string,int> si;
typedef map<string,string> ss;
typedef pair<string, int> psi;

bool comparator(psi first, psi second) {
  if (first.second >= second.second)
    return true;
  return false;
}

int main() {

  int cases;
  cin >> cases;

  while (cases --) {

    si VoteCount;
    ss Party;

    int candidates;

    cin >> candidates >> ws;

    for (int i = 0; i < candidates; ++i) {
      string name;
      string party;

      getline(cin, name);
      getline(cin, party);

      // Populate data structure
      VoteCount[name] = 0;
      Party[name] = party;
    }

    int votes;
    cin >> votes >> ws;

    for (int i = 0; i < votes; ++i) {
      string name;
      getline(cin, name);

      // Update Data Structure with tallies of known names only
      if(VoteCount.find(name) != VoteCount.end())
        VoteCount[name]++;
    }

    // Put pairs into vector so we can sort them
    vector<psi> SortedCounts(VoteCount.begin(), VoteCount.end());
    sort(SortedCounts.begin(),SortedCounts.end(), &comparator);


    // Check for tie or Print winning party.
    if(SortedCounts[0].second == SortedCounts[1].second)
      cout << "tie" << endl;
    else
      cout << Party[SortedCounts[0].first] << endl;

    // Separate cases by newline
    if(cases)
      cout << endl;

    // WS between cases... fun times
    cin >> ws;
  }

  return 0;
}