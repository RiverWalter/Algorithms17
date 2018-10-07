#include "../../include/headers.h"

//EuclidGCDR tests
void TestEuclidGCDR(int a, int b)
{
    int gcd = EuclidGCDR(a, b);
    printf("The GCD of %d and %d is %d\n", a, b, gcd);
}
void TestEuclidGCDStepsR(int a, int b)
{
    printf("Finding the GCD of %d and %d using Euclid's algorithm\n", a, b);
    auto a0 = a, b0 = b;
    printf("\ta\tb\tr\tq\n");
    int r, q;
    while (b) {
        r = a % b;
        q = a / b;
        printf("\t%d\t%d\t%d\t%d\n", a, b, r, q);
        a = b;
        b = r;
    } ;
    printf("\t%d\t%d\t%d\t-\n", a, b, r);
    printf("The GCD of %d and %d is %d\n", a0, b0, a);
}
void TestEuclidGCDTypicalCasesR(bool showSteps)
{
#define N 22
    int ab[N][2] = {
        //Wikipedia
        { 252, 105 },
        //Introduction to Algorithms
        { 30, 21 },
        { 99, 78 },
        //https://www.calculatorsoup.com/
        { 816, 2260 },
        //Algorithms, S. Dasgupta
        { 1035, 759 },
        //http://everything.explained.today
        { 1386, 3213 },
        //https://www.cs.cornell.edu
        //Example of Extended Euclidean Algorithm
        { 84, 33 },
        { 432, 95256 },
        //https://www.rit.edu, The Euclidean Algorithm
        { 12, 18 },
        { 24, 54 },
        { 168, 180 },
        { 244, 354 },
        { 128, 423 },
        { 406, 555 },
        { 220, 1323 },
        { 3846, 153 },
        { 1424, 3084 },
        { 2415, 3289 },
        { 4278, 8602 },
        //Other
        { 72, 84 },
        { 102, 138 },
        { 26187, 1533 }
    };
    for (int i = 0; i < N; i++) {
        if (showSteps)
            TestEuclidGCDStepsR(ab[i][0], ab[i][1]);
        else
            TestEuclidGCDR(ab[i][0], ab[i][1]);
        printf("\n");
    }
}