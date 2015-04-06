#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;
typedef std::numeric_limits< double > dbl;

int main() {
  double num,den;

  while(cin >> num >> den) {
    double d = num/den;
    // cout.precision(dbl::digits10 + 40);
    // cout << fixed << d << endl;
    // printf("%0.50f\n", d);
  }
  return 0;
}