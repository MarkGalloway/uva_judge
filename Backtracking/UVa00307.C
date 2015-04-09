#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <algorithm>
#include <bitset>

using namespace std;

typedef vector<int> vi;
typedef set<int> si;
typedef vector<bool> vb;

int N, length, num_sticks, stick_sum;
vi sticks;
si lengths;
vb used;

// bool memo[10000][1000];


/*
 * Precalculate possible stick lengths
 */
void precalculate_lengths(int sum, int max) {
  for (int length = max; length <= sum; ++length) {
    if(sum % length == 0) {
      lengths.insert(length);
    }
  }
}

bool backtrack(int index, int current_length, int remaining, int pieces_left) {

  // Basecase, we are out of sticks
  if(pieces_left == 0 && remaining == 0) {
    return true;
  }
  else if(remaining == 0 || pieces_left == 0)
    return false;

  // if(pieces_left == 0)
  //   return true;

  // Prune: This length combo has failed already
  // if(!memo[current_length][pieces_left]) return false;


  // Prune: Smallest unused is larger than remaining length
  int smallest = 99999;
  for (int i = N-1; i > 0; --i)
    if(!used[i]) {
      smallest = sticks[i];
      break;
    }
  if(smallest > remaining) return false;

  // Prune: Largest unused is larger than remaining length
  // int largest = -1;
  // for (int i = 0; i < N; ++i)
  //   if(!used[i]) {
  //     largest = sticks[i];
  //     break;
  //   }
  // if(largest > remaining) return false;

  bitset<100> tried;

  // Recursive case: Build the stick
  for (int i = index; i < N; ++i) {
    // Prune: Stick is used
    if(used[i]) continue;

    // Prune: Stick is too large
    if(current_length + sticks[i] > length) continue;

    // Prune: This length combo has failed already
    // if(!memo[current_length + sticks[i]][pieces_left-1]) continue;

    // Prune: Already tried this length
    if(tried.test(i)) continue;

    // If the next stick fits
    if(current_length + sticks[i] < length) {
      used[i] = true;
      if(backtrack(i+1, current_length + sticks[i], remaining - sticks[i], pieces_left - 1)) return true;
      // memo[current_length + sticks[i]] = false;
      // memo[current_length][sticks[i]] = false;
      // memo[current_length + sticks[i]][pieces_left-1] = false;
      used[i] = false;
      tried.set(i);
    }
    // Completed a stick
    else {
      used[i] = true;
      if(backtrack(0, 0, remaining - sticks[i], pieces_left - 1)) return true;
      // memo[current_length][sticks[i]] = false;
      // memo[current_length + sticks[i]][pieces_left-1] = false;
      used[i] = false;
      tried.set(i);
    }

  }
  // Matching failed
  // memo[current_length][pieces_left-1] = false;
  return false;
}

int main() {

  while (1) {
    cin >> N >> ws;

    // End of cases
    if(N == 0) break;

    // Init
    sticks.assign(N, 0);
    used.assign(N, false);
    lengths.clear();
    stick_sum = 0;

    int max_stick = -1;
    // Read in the sticks
    for (int i = 0; i < N; ++i) {
      cin >> sticks[i];

      // Track the sum of sticks
      stick_sum += sticks[i];

      // Track the largest stick we've seen.
      if(sticks[i] > max_stick)
        max_stick = sticks[i];
    }

    sort(sticks.begin(), sticks.end(), greater<int>());

    // Precalculate
    precalculate_lengths(stick_sum, max_stick);

    // for(auto it = lengths.begin(); it != lengths.end(); ++it) {
    //   length = *it;
    //   num_sticks = stick_sum/length;
    //   cout << *it << " ";
    //   cout << "length: " << length << " num_sticks: " << num_sticks << " stick sum: " << stick_sum << endl;
    // }
    // cout << endl << endl;

     // Backtrack on each possible stick length
    for(auto it = lengths.begin(); it != lengths.end(); ++it) {

      // memset(memo, true, sizeof memo);

      length = *it;
      num_sticks = stick_sum/length;

      // cout << "length: " << length << " num_sticks: " << num_sticks << " stick sum: " << stick_sum << endl;

      if(backtrack(0, 0, stick_sum, N)) {
        // Solution found
        cout << length << endl;
        break;
      }
    }
  }

  return 0;
}