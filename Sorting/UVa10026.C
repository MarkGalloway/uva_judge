/* UVa problem: 10026 Shoemaker's Problem
 *
 * Topic: Sorting
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Time Scheduling Problem. Choose order of jobs that take time(days)
 *   and fine(cents/day) to minimize total fine.
 *
 * Solution Summary:
 *
 *   Sort jobs based on fine/time ratio to present greedy solution
 *
 * Used Resources:
 *
 *   Competitive Programming 3
 *   Howard Cheng's hint
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, double> id;
typedef vector<id> vid;

int N;
vid jobs;

/*
 * Sorts pairs of <int,double> by larger double
 * value first, followed by smaller int value second
 */
bool comparator(id a, id b) {
  if(a.second == b.second)
    return a.first < b.first;
  else
    return a.second > b.second;
}


int main() {
  int cases;
  cin >> cases;

  while(cases--) {
    // gobble blank line
    cin >> ws;

    // Init
    jobs.clear();

    // Read in tasks
    cin >> N;
    int t, f;
    for (int i = 1; i <= N; ++i) {
      cin >> t;
      cin >> f;
      // Store (job, fine/time) pair
      jobs.push_back(id(i, (double)f/t));
    }

    // Sort
    sort(jobs.begin(), jobs.end(), comparator);

    // Print solution
    for (vid::iterator i = jobs.begin(); i != jobs.end(); ++i) {
      cout << (*i).first;
      if(i + 1 != jobs.end())
        cout << " ";
    }
    cout << endl;

    // Blank line between cases
    if(cases)
      cout << endl;
  }

  return 0;
}