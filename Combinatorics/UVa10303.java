/* UVa problem: 10303 How Many Trees?
 *
 * Topic: Combinatorics
 *
 * Level: non-trivial
 *
 * Brief problem description:
 *
 *   Calculate Calatan(n) for  1 <= N <= 1000
 *
 * Solution Summary:
 *
 *   Precompute Catalan numbers using Java Big Integer
 *   Used bottom up formula from the textbook
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

import java.util.Scanner;
import java.math.BigInteger;

class Main {

    public static void main(String[] args) {
        // Init
        Scanner sc = new Scanner(System.in);

        // Precompute Catalan numbers
        BigInteger []catalan = new BigInteger[1001];
        catalan[1] = BigInteger.ONE;

        for(int i = 2; i < 1001; ++i) {
            catalan[i] = BigInteger.valueOf(2*i*(2*i-1)).multiply(catalan[i-1]).divide(BigInteger.valueOf((i+1)*i));
        }

        while(sc.hasNext()) {
            int n = sc.nextInt();

            // Print solution
            System.out.println(catalan[n]);
        }

        sc.close();
    }
}