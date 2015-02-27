/* UVa problem: 655 False Coin
 *
 * Topic: Data structures: heaps, priority queues, etc.
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   There are N coins. One is fake and does not weight the same as
 *   the real ones. A bunch of scale readings are performed and the
 *   results may be able to determine which coin is the fake.
 *
 * Solution Summary:
 *
 *   I used a 1D array to indicate false/real status. As hinted by *   the book,
 *   each scale reading is a logical determiner for the
 *   status of the coins.
 *   '=' indicates that all coins weighed are real.
 *   '<' or '>' indicate that all coins not weighed are real.
 *   After applying this boolean logic to the 1D array,
 *   we can see if there is only one false coin contained in the
 *   resultant array.
 *
 * Used Resources:
 *
 *   Competitive Programming 3
 *
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

// Returns 1 if array contains the element, 0 otherwise
int array_contains(int * array, int size, int element) {
  for (int i = 0; i < size; ++i)
    if(array[i] == element)
      return 1;
  return 0;
}

int main() {
  // Read in number of datasets
  int cases;
  cin >> cases >> ws;

  // Read in each dataset
  while(cases--) {
    int num_coins, num_weighings;
    cin >> num_coins >> num_weighings;

    int coin_status[num_coins];

    // Initialize all coins to 'false'
    for (int i = 0; i < num_coins; ++i)
      coin_status[i] = 0;

    // Read in each weighing
    for (int i = 0; i < num_weighings; ++i) {
      int num_weighed_coins;
      cin >> num_weighed_coins;
      int current_weighing[num_weighed_coins * 2];

      // Read in the coins for this weighing
      for (int j = 0; j < num_weighed_coins*2; ++j) {
        int coin;
        cin >> coin;
        current_weighing[j] = coin;
      }

      // Read in the scale result
      char result;
      cin >> result;

      // Process this weighing
      if(result == '=') {
        // None of the weighed coins are fake
        for (int k = 0; k < num_weighed_coins*2; ++k) {
          int index = current_weighing[k] - 1;
          coin_status[index] = 1;
        }
      }
      else if (result == '<' || result == '>') {
        for (int j = 0; j < num_coins; ++j) {
          if(!array_contains(current_weighing, num_weighed_coins*2, j+1)) {
            coin_status[j] = 1;
          }
        }
      }
    }

    // Analyze the resultant array
    int fake_index = -1;
    int fake_count = 0;

    for (int j = 0; j < num_coins; ++j)
    {
      if(coin_status[j] == 0) {
        fake_count++;
        fake_index = j + 1;
      }
    }

    // Print result for this test case.
    if(fake_count != 1)
      cout << 0 << endl;
    else
      cout << fake_index << endl;

    // Print a blank line between datasets
    if(cases > 0)
      cout << endl;
  }

  return 0;
}