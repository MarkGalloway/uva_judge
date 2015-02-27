/* UVa problem: 11402 Ahoy, Pirates!
 *
 * Topic: Data structures: heaps, priority queues, etc.
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   There are two types of pirates represented in the input as a string.
 *   This string must handle updates to ranges of string which change a
 *   pirates status from one side to the other or inverts a portions of
 *   the sub string. Additionally, a range of the string will be queried
 *   to find out the count of pirates on one side within that range.
 *
 * Solution Summary:
 *
 *   As hinted by the book and the fact that frequent updates/queries
 *   must be made to portions of the string, I implemented a Segment Tree
 *   data structure (closely resembling the code from the book, initially).
 *   Once functional, this gave me a TLE, so I had to figure out the lazy
 *   propogation additions to this data structure.
 *
 *   A major pitfall encountered after implementing the lazy propagation
 *   was that consequtive updates were actually "clobbering" previously
 *   queued lazy updates, since these updates were not propagating due to
 *   no query to that portion of the tree. I only realized what was
 *   happening when I drew out and manually operated on an example. To
 *   solve this I realized that I needed to combine consequetive updates,
 *   eg/
 *      inverse(inverse()) = do nothing
 *      inverse(buccaneer()) = barbary
 *
 *   Overall, I found this problem to be a lot more involved than the others
 *   I have tried so I may try to champion it.
 *
 * Used Resources:
 *
 *    - Competitive Programming 3
 *         - initial segment tree code provided (p.57)
 *    - http://se7so.blogspot.ca/2012/12/segment-trees-and-lazy-propagation.html
 *         - I had a difficult time figuring out how to preform lazy
 *           propagation so I followed this example as a reference.
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

const int OUT_OF_RANGE = -1;
const int NOT_LAZY = 0;
const int BARBARY = 1;
const int BUCCANEER = 2;
const int INVERSION = 3;


class SegmentTree {
public:
  SegmentTree(const string &str) : pirates(str) {
      n = pirates.length();
      st.assign(4 * n, 0); // create large enough vector
      lazy.assign(4 * n, NOT_LAZY);
      build(1, 0, n - 1);   // recursive build
    }


  // Query tree to get Buccanneer count in range [i,j]
  int lazy_query(int i, int j) {
    return lazy_query(1, 0, n-1, i, j);
  }


  // Update the tree to mutate range [i,j] to value
  // if value == -1, invert range pirates.
  void lazy_update(int i, int j, int value) {
    lazy_update(1, 0, n-1, i, j, value);
  }


private:
  string pirates;
  int n;
  vi st, lazy;


  /*
   * Accessors
   */
  int left (int parent) { return parent << 1; }
  int right(int parent) { return (parent << 1) + 1; }


  /*
   * Returns the integer representation of the string index character
   */
  int get_pirate_type(int index) {
    return (pirates.at(index) == '0')? BARBARY : BUCCANEER;
  }


  /*
   * Build The Tree
   */
  void build(int node, int L, int R) {
    if(L > R) return;
    if (L == R)  // Base Case, Leaf node
      st[node] = get_pirate_type(L) - 1; // store the pirate type
    else {
      // Recursively build children
      build(left(node), L, (L + R) / 2);
      build(right(node), (L + R) / 2 + 1, R);

      // Pirate count for this node is recursive sum of children.
      int lval = st[left(node)];
      int rval = st[right(node)];
      st[node] = lval + rval;
    }
  }

  /*
   * Applies inversion to the currently specified operation
   */
  int invert_update(int update) {
    if(update == INVERSION)
      return NOT_LAZY;
    if(update == BUCCANEER)
      return BARBARY;
    if(update == BARBARY)
      return BUCCANEER;
    return INVERSION;
  }

  /*
   * Performs the update specified to the node and propagates
   * the operation as lazy to the children (if necessary)
   */
  void update_node(int node, int L, int R, int update) {
    // Preform update to node
    if(update == BUCCANEER)      st[node] = R - L + 1;
    else if(update == BARBARY)   st[node] = 0;
    else if(update == INVERSION) st[node] = R - L + 1 - st[node];

    // We're a leaf
    if(L == R) return;

    // If we're not a leaf, propagate a lazy op to children
    if(update == INVERSION) {
      // Need to invert the already queued lazy OP
      lazy[left(node)]  = invert_update(lazy[left(node)]);
      lazy[right(node)] = invert_update(lazy[right(node)]);
    }
    else
      lazy[left(node)] = lazy[right(node)] = update;
  }


  /*
   * Queries the tree for range [i,j] recursively. Will
   * execute and propagate lazy updates node by node
   * until range is found
   *
   */
  int lazy_query(int node, int L, int R, int i, int j) {

    // Current segment outside range [i, j]
    if (L > R || i > R || j < L) return OUT_OF_RANGE;

    // Preform lazy update if needed
    if(lazy[node]) {
      update_node(node, L, R, lazy[node]);
      lazy[node] = NOT_LAZY;
    }

    // Inside query range, return the value
    if (L >= i && R <= j) return st[node];

    // Compute the bucaneer count recursively
    int lval = lazy_query(left(node), L, (L+R) / 2, i, j);
    int rval = lazy_query(right(node), (L+R) / 2 + 1, R, i, j);

    // Left segment outside query
    if (lval == OUT_OF_RANGE) return rval;
    // Right segment outside query
    if (rval == OUT_OF_RANGE) return lval;

    return lval + rval;
  }


  /*
   * Updates the tree for range [i,j] recursively. Will
   * execute and propagate lazy updates node by node
   * until range is found
   *
   */
  void lazy_update(int node, int L, int R, int i, int j, int value) {

    // Preform lazy update if needed
    if(lazy[node]) {
      update_node(node, L, R, lazy[node]);
      lazy[node] = NOT_LAZY;
    }

    // Current segment is not within range [i, j]
    if(L > R || i > R || j < L)
      return;

    // Segment is fully within range, update
    if(L >= i && R <= j) {
      update_node(node, L, R, value);
      return;
    }

    // Segment is split, this node is recursive sum of children.
    lazy_update(left(node), L, (L+R) / 2, i, j, value);
    lazy_update(right(node), (L+R) / 2 + 1, R, i, j, value);

    st[node] = st[left(node)] + st[right(node)];
  }
};


int main() {

  int cases;
  int case_count = 0;
  cin >> cases;

  while(cases--) {
    int sets;
    cin >> sets;

    // Read in the sets of pirates
    string pirates;
    while(sets--) {
      int reps;
      string sub;
      cin >> reps; // repitions of substr
      cin >> sub; // substr

      for (int i = 0; i < reps; ++i)
        pirates += sub;
    }

    // Build Segment Tree using pirates string
    SegmentTree segT(pirates);

    // Start Reading Queries
    cout << "Case " << ++case_count << ":" << endl;
    int queries;
    int count = 0;
    cin >> queries;

    while(queries--) {
      char q;
      int i, j;
      cin >> q >> i >> j;

      if(q == 'F')
        segT.lazy_update(i, j, BUCCANEER);
      else if (q == 'E')
        segT.lazy_update(i, j, BARBARY);
      else if (q == 'I')
        segT.lazy_update(i, j, INVERSION);
      else if (q == 'S') {
        // output God's query
        int result = segT.lazy_query(i, j);
        cout << "Q" << ++count << ": " << result << endl;
      }
    }
  }
  return 0;
}