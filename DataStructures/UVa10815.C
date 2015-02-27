/* UVa problem: 10815 Andy's First Dictionary
 *
 * Topic: Data structures: heaps, priority queues, etc.
 *
 * Level: trivial
 *
 * Brief problem description:
 *
 *   Parse the input for distinct words and output them in an
 *   alphabetically sorted order.
 *
 * Solution Summary:
 *
 *   I simply parsed the input for words, and then added them to a
 *   set. I then printed out the set (which sorts internally).
 *
 * Used Resources:
 *
 *   Competitive Programming 3
 *
 * I hereby certify that I have produced the following solution myself
 * using the resources listed above in accordance with the CMPUT 403
 * collaboration policy.
 *
 * --- Mark Galloway
 */

#include <iostream> // cin+cout
#include <set>      // set
#include <string>   // string

using namespace std;

int main() {
  string line;
  set<string> dictionary;
  while(getline(cin, line)) {

    string word;

    for (size_t i = 0; i < line.length(); ++i) {
      // parse each character
      char c = line[i];

      // alphabetic characters only
      if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        word += tolower(c);
        if(i == line.length()-1) {
          // end of line indicates end of word
          dictionary.insert(word);
          word.erase();
        }
      }
      else {
        // tricky, was adding empty string
        // when encountering sequential non-alphabetic
        if(word.compare("") != 0) {
          dictionary.insert(word);
        }

        // non-alphabetic indicates new word
        word.erase();
      }
    }
  }

  // print sorted dictionary
  set<string>::iterator it = dictionary.begin();
  set<string>::iterator end = dictionary.end();
  for ( ; it != end; ++it)
    cout << *it << endl;

  return 0;
}
