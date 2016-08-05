/* UVa problem: 00856 The Vigenère Cipher
 *
 * Topic: String (search, manipulation, matching)
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   A plaintext string is encoded to a ciphertext string using
 *   a key string during the Vigenère Cipher transformation.
 *   Given the plaintext and ciphertext, find all possible keys
 *   and print them out in the format "Key -> ciphertext".
 *   The ciphertext is known to be a concatenation of single
 *   digit word representations such as "sixsixtwo" or "sixsixone".
 *
 * Solution Summary:
 *
 *   The algorithmic idea here is to use nested looping to produce
 *   all possible plaintext outputs and then generate the keys which
 *   would tranform the ciphertext to the plaintext using
 *   Vigenère square math:
 *      Ci = Pi + Kj  (mod 26)
 *
 * Used Resources:
 *
 *   - Competitive Programming 3
 *   - My notes from CMPUT 210 to remember the Vigenère calculations
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream>
#include <map>

using namespace std;

std::map<int, string> number_to_word = {
  {0, "zero"},
  {1, "one"},
  {2, "two"},
  {3, "three"},
  {4, "four"},
  {5, "five"},
  {6, "six"},
  {7, "seven"},
  {8, "eight"},
  {9, "nine"},
  };

/*
 * Takes three number arguments and returns the corresponding
 * concatenated string containing each arguments word
 * representation.
 */
string build_number_string(int i, int j, int k) {
  return number_to_word[i] + number_to_word[j] + number_to_word[k];
}

/*
 * Takes a char argument and turns it into the corresponding
 * number value, based on 'A' == 1.
 */
int to_digit(char a) {
  int ans =  a - 'A' + 1;
  return ans;
}

/*
 * Takes a number argument and turns it into the corresponding
 * capital letter value, based on 'A' == 1.
 */
char to_char(int digit) {
  if (digit == 0)
    digit = 26;
  int ans = digit + 'A' - 1;
  return ans;
}

/*
 *  Takes a plaintext and ciphertext string and returns the key
 *  which corresponds to the viginere transformation of that
 *  plaintext to ciphertext
 */
string build_key_string(string ciphertext, string plaintext) {
  string key = "";
  for (size_t i = 0; i < ciphertext.length(); ++i) {
    int key_digit = (to_digit(ciphertext[i])
                     - to_digit(toupper(plaintext[i])) + 26) % 26;
    key += to_char(key_digit);
  }

  return key;
}


int main() {

  string ciphertext;
  getline(cin, ciphertext);

  while(1) {
    // Process word
    size_t cipher_length = ciphertext.length();

    for (int i = 9; i >= 0; --i) {
      for (int j = 9; j >= 0; --j) {
        for (int k = 9; k >= 0; --k) {
          // Build the string of possible plaintext
          string plaintext = build_number_string(i,j,k);

          // Lengths need to be the same
          if(plaintext.length() != cipher_length)
            continue;

          // Figure out the key for each letter.
          string key = build_key_string(ciphertext, plaintext);

          cout << key << " -> " << plaintext << endl;
        }
      }
    }

    // See if there is another case to process...
    if(getline(cin, ciphertext))
      cout << endl; // Empty line between cases
    else
      break;
  }

  return 0;
}