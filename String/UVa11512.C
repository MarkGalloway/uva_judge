/* UVa problem: 11512 GATTACA
 *
 * Topic: String (search, manipulation, matching)
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Find the longest repeating substring and it's number of
 *   repetitions.
 *
 * Solution Summary:
 *
 *   I chose to implement the suffix array data structure that was
 *   presented in the book. Much of the source code is taken directly
 *   from the book. I chose to encapsulate much of the global data
 *   into a class structure to make things more simple.
 *
 *   After computing the Longest Repeating Substring from the
 *   Suffix array, I simply using STL find to count the repetitions.
 *
 * Used Resources:
 *
 *   - Competitive Programming 3
 *     - Much of the algorithmic implementations for the
 *       suffix array and LCP are taken right from the book
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> ii;

const int MAX_N = 1010;

class SuffixArray {
public:
  SuffixArray(const string s) : data(s), n(data.length()) {
    RA = new int[n]();
    SA = new int[n]();
    tempRA = new int[n]();
    tempSA = new int[n]();
    LCP = new int[n]();
    PLCP = new int[n]();
    Phi = new int[n]();

    constructSA();
  }

  ~SuffixArray() {
    delete [] RA;
    delete [] tempRA;
    delete [] SA;
    delete [] tempSA;
    delete [] LCP;
    delete [] PLCP;
    delete [] Phi;
  }

  /*
   *  Calculates and returns the Longest Repeating Substring
   */
  string getLRS() {
    computeLCP();
    ii length_index = computeLRS();

    // There is no LRS
    if(length_index.first == 0)
      return "";

    // Return the string from of the LRS
    return data.substr(SA[length_index.second], length_index.first);
  }

private:
  const string data;
  const int n;
  int *RA, *tempRA; // Rank array and temporary rank array
  int *SA, *tempSA; // Suffix array and temporary suffix array
  int *LCP, *PLCP;  // LCP[i] stores the LCP between previous suffix T+SA[i-1]
                    // and current suffix T+SA[i]
  int *Phi;         // for computing longest common prefix

  // Counting/Radix sort (provided by textbook)
  void countingSort(int k) {
    int sum, maxi = max(300, n);  // up to 255 ASCII chars or length of n
    int c[MAX_N] = {0};

    // Count the frequency of each integer rank
    for (int i = 0; i < n; i++)
      c[i + k < n ? RA[i + k] : 0]++;
    for (int i = sum = 0; i < maxi; i++) {
      int t = c[i];
      c[i] = sum;
      sum += t;
    }
    for (int i = 0; i < n; i++)          // shuffle the suffix array if necessary
      tempSA[c[SA[i]+k < n ? RA[SA[i]+k] : 0]++] = SA[i];
    for (int i = 0; i < n; i++)          // update the suffix array SA
      SA[i] = tempSA[i];
  }

  // Suffix Array building (provided by textbook)
  void constructSA() {
    int r;

    // Initialize
    for (int i = 0; i < n; i++) {
      RA[i] = data[i]; // Initial rankings
      SA[i] = i;       // Initial SA: {0, 1, 2, ..., n-1}
    }

    // Repeat sorting process log n times
    for (int k = 1; k < n; k <<= 1) {
      // actually radix sort: sort based on the second item
      countingSort(k);
      // then (stable) sort based on the first item
      countingSort(0);

      // re-ranking; start from rank r = 0
      tempRA[SA[0]] = r = 0;
      for (int i = 1; i < n; i++)  // compare adjacent suffixes
        tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
        (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
      for (int i = 0; i < n; i++)      // update the rank array RA
        RA[i] = tempRA[i];
      if (RA[SA[n-1]] == n-1) break;  // nice optimization trick
    }
  }

  // Compute Longest Common Prefix (modified from textbook)
  void computeLCP() {
    int i, L;
    Phi[SA[0]] = -1;           // default value
    for (i = 1; i < n; i++)    // compute Phi in O(n)
      Phi[SA[i]] = SA[i-1];    // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++) {   // compute Permuted LCP in O(n)
      if (Phi[i] == -1) {
        PLCP[i] = 0;  // special case
        continue;
      }
      while (data[i + L] == data[Phi[i] + L])
        L++;       // L increased max n times
      PLCP[i] = L;
      L = max(L-1, 0);    // L decreased max n times
    }
    for (i = 0; i < n; i++)   // compute LCP in O(n)
      LCP[i] = PLCP[SA[i]];   // put the permuted LCP to the correct position
  }

  /* Compute Longest Repeating Substring (modified from textbook)
   * returns a pair (the LRS length and its index)
   */
  ii computeLRS() const {
    int idx = 0, maxLCP = 0;
    for (int i = 1; i < n; i++)   // O(n), start from i = 1
      if (LCP[i] > maxLCP)
        maxLCP = LCP[i], idx = i;
    return ii(maxLCP, idx);
  }
};

int main() {

  int cases;
  cin >> cases;

  while(cases--) {
    string line;
    cin >> line;

    line += '$';

    SuffixArray sa(line);

    string lrs = sa.getLRS();

    if(lrs == "")
      cout << "No repetitions found!" << endl;
    else {
      // Count the repetitions!
      int count = 0;

      size_t result = line.find(lrs);
      while (result != string::npos && ++count)
        result = line.find(lrs, result + 1);

      // Print answer
      cout << lrs << " " << count << endl;
    }
  }

  return 0;
}