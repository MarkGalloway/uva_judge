/* UVa problem: 11837 Musical Plagiarism
 *
 * Topic: String (search, manipulation, matching)
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Given a string of notes representing a "song", and a string of
 *   notes representing a "suspect snippet", determine if the
 *   suspect snippet is plagiarizing the original song.
 *
 * Solution Summary:
 *
 *   Find the distances between the notes in the song and the
 *   suspect snippet. Then process these distance sequences using
 *   KMP pattern matching algorithm. If a distance match is found,
 *   the song is plagiarized;
 *
 * Used Resources:
 *
 *   - Competitive Programming 3
 *     - Base source code for KMP
 *   - Howard Cheng's Hint
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

using namespace std;

typedef vector<int> vi;

const int MAX_N = 100000;
int b[MAX_N]; // back table

map<string, int> notes = {
    {"B#", 0},
    {"C" , 0},
    {"C#", 1},
    {"Db", 1},
    {"D" , 2},
    {"D#", 3},
    {"Eb", 3},
    {"E" , 4},
    {"Fb", 4},
    {"E#", 5},
    {"F" , 5},
    {"F#", 6},
    {"Gb", 6},
    {"G" , 7},
    {"G#", 8},
    {"Ab", 8},
    {"A" , 9},
    {"A#", 10},
    {"Bb", 10},
    {"Cb", 11},
    {"B" , 11}};

/*
 * Preprocess string P to fill the back table
 */
void kmpPreprocess(const vector<int> &P) {
  int i = 0, j = -1, m = P.size();
  b[0] = -1; // starting values

  // pre-process the pattern string P
  while (i < m) {
    while (j >= 0 && P[i] != P[j])
      j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    b[i] = j;
  }
}

/*
 * Modified KMP which returns true on the first match of P in T
 */
bool kmpSearch(const vector<int> &P, const vector<int> &T) {
  int i = 0, j = 0, n = T.size(), m = P.size(); // starting values

  while (i < n) { // search through string T
    while (j >= 0 && T[i] != P[j])
      j = b[j]; // if different, reset j using b
    i++; j++; // if same, advance both pointers
    if (j == m) {
      // a match found when j == m
      return true;
    }
  }
  return false;
}

/*
 * Transforms a note to its integer representation.
 */
int processNote(string note) {
  int n = notes[note];
  return (n + 12) % 12;
}

int main() {

  while(1) {
    int m, t;
    cin >> m >> t >> ws;

    // End of cases is "0 0"
    if(m == 0 && t == 0) break;

    vi song, suspect;
    string note;
    int prev, curr;

    // Proccess song notes to distance array
    cin >> note >> ws;
    prev = processNote(note);
    for (int i = 1; i < m; ++i) {
      cin >> note >> ws;
      curr = processNote(note);
      int dist = (curr - prev + 12) % 12;
      song.push_back(dist);
      prev = curr;
    }

    // Proccess suspect notes to distance array
    cin >> note >> ws;
    prev = processNote(note);
    for (int i = 1; i < t; ++i) {
      cin >> note >> ws;
      curr = processNote(note);
      int dist = (curr - prev + 12) % 12;
      suspect.push_back(dist);
      prev = curr;
    }

    // Search for suspect distance array in song distance array
    kmpPreprocess(suspect);
    bool match = kmpSearch(suspect, song);

    if(match)
      cout << "S" << endl;
    else
      cout << "N" << endl;
  }

  return 0;
}