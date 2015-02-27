#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef vector<bool> vb;

vi pieces;
si lengths;
vb used;

int sticks, length, n;


/*
 * Precompute possible stick lengths
 */
void precompute_sticks(int sum, int max) {
  for (int num_sticks = 1; num_sticks <= sum; ++num_sticks) {
    // A possible number of sticks is a divisor of sum
    if(sum % num_sticks == 0) {
      // length of each stick cannot be greater than largest stick
      if(sum/num_sticks <= max) {
        lengths.insert(num_sticks);
      }
    }
  }
}

bool backtrack_sticks(int index, int current_length, int sticks_left) {
  // Basecase: Current stick is at length
  if(current_length == length) {

    // cout << "DEBUG: formed stick. pieces left: " << sticks_left << endl;

    // We have used all sticks
    if(sticks_left == 0) {
      // cout << "WIN" << endl;
      return true;
    }

    // Start the next stick
    index = 0;
    current_length = 0;

    // for (int i = 0; i < n; ++i) {
    //   if(!used[i]) {
    //     used[i] = true;
    //     current_length = pieces[i];
    //     cout << "DEBUG: Index is... " << i << endl;
    //     cout << "DEBUG: Adding " << pieces[i] << endl;
    //     --sticks_left;
    //     index = 0;
    //     break;
    //   }
    // }
  }
  // if(used[3]) {
  //   cout << "WTF true" << endl;
  // } else {
  //   cout << "WTF false" << endl;
  // }

  // Recursive case: Choose next piece
  // cout << "DEBUG: Index is... " << index << endl;
  for (int i = index; i < n; ++i) {
    if(!used[i] /*&& (pieces[i] + current_length <= length) */) {
      if(pieces[i] + current_length <= length) {
        used[i] = true;
        // cout << "DEBUG: Index is... " << i << endl;
        // cout << "DEBUG: Adding "<< current_length <<" + " << pieces[i] << endl;
        bool rval = backtrack_sticks(i, pieces[i] + current_length, sticks_left-1);
        if(rval)
          return true;
        // cout << "DEBUG: Removing " << pieces[i] << endl;
        used[i] = false;
      }
      else {
        // cout << "DEBUG: Rejecting "<< current_length <<" + " << pieces[i] << endl;
      }
    }
  }
  // cout << "DEBUG: Failed, backtracking" << endl;
  // Failed to make stick of this length
  return false;
}

int main() {
  while (1) {
    cin >> n;

    // End of Cases
    if(n == 0)
      break;

    // Prep for case
    pieces.clear();
    lengths.clear();
    used.clear();


    int stick, stick_sum = 0, max_stick = -1;
    for (int i = 0; i < n; ++i) {
      // Read in sticks
      cin >> stick;
      pieces.push_back(stick);
      used.push_back(false);

      // Track the sum of sticks
      stick_sum += stick;

      // Track the largest stick we've seen.
      if(stick > max_stick)
        max_stick = stick;
    }

    // Precomputation
    precompute_sticks(stick_sum, max_stick);

    // for(auto it = lengths.begin(); it != lengths.end(); ++it) {
    //   cout << *it << " ";
    // }
    // cout << endl;

    // Backtrack on each possible stick length
    for(auto it = lengths.begin(); it != lengths.end(); ++it) {

      length = *it;
      // length = 6;
      // sticks = 4;
      sticks = stick_sum/(*it);

      cout << "Trying Length = " << length << " Sticks = " << sticks << endl;

      used[0] = true;
      if(backtrack_sticks(1, pieces[0], n-1)) {
        // Solution found
        cout << length << endl;

        break;
      }
    }
  }
  return 0;
}