/* UVa problem: 10608 Friends
 *
 * Topic: Data structures: heaps, priority queues, etc.
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   A town has N citizens. Among these citizens there are M
 *   friendships. Friendships are transitive. (Friends form a set)
 *   We want to know the largest group of friends. (Find the
 *   largest set)
 *
 * Solution Summary:
 *
 *   I chose to implement the Union-Find Disjoint Sets algorithm as
 *   this problem is mainly about testing set membership and merging
 *   disjoint sets, and the UFDS algorithm with path compression is
 *   extremely efficient.
 *   The data structures used were a vector of integers, where each
 *   index represented a person in the town and the value at that
 *   index represented the set they belonged to (initially, just a
 *   self-reference). A second vector of integers was used to
 *   keep track of set size by index.
 *
 * Used Resources:
 *
 *   - UFDS as presented in 2.4.2 of Competitive Programming 3
 *   - Howard Cheng's hint:www.cs.uleth.ca/~cheng/contest/hints.html
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream> // for print
#include <vector> // for vector
#include <algorithm> // for max_element

using namespace std;

typedef vector<int> vi;

vi set;  // a list of set representatives for each element
vi set_size; // the set_size of elements in each set


/*
 * Recursively finds the set representative for the element i
 * Performs path compression (prunes indirect representation)
 */
int find(int i) {
  // Base case: i is the representative
  if(set[i] == i) return i;

  // Prune the indirect representation
  set[i] = find(set[i]);  // 5 -> 6 -> 7

  // Recursive Case
  return set[i];
}


/*
 * Merges the two sets represented by elements u and v
 */
void merge(int u, int v) {
  // find setresentatives
  u = find(u);
  v = find(v);

  // merge the sets
  set[u] = v;

  // update set_size
  set_size[v] += set_size[u];
  set_size[u] = set_size[v];
}


/*
 * Performs the union-find algorithm for each input pair (a,b)
 * and returns the size of the largest resultant set
 */
int union_find(int n, int m) {

  // Initialize data structures
  set.assign(n, 0);
  set_size.assign(n, 1);

  for (int i = 0; i < n; ++i)
  {
    set[i] = i;
  }

  // Read in each pair of friends
  for (int i = 0; i < m; ++i)
  {
    int a,b;

    // read in pair
    cin >> a >> b;

    // normalize index to start at zero
    a -= 1;
    b -= 1;

    // Case 1: sets are disjoint, merge
    if(find(a) != find(b)) {
      merge(a, b);
    }

    // Case 2: Same set, do nothing
  }

  // find the largest set_size
  int max = *max_element(set_size.begin(), set_size.end());

  return max;
}

/*
 *  Read input and launch solve method on each case
 */
int main() {

  int cases;
  cin >> cases;

  while(cases--) {
    int n,m;
    cin >> n >> m;

    // preform union find and print result
    cout << union_find(n,m) << endl;
  }

  return 0;
}
