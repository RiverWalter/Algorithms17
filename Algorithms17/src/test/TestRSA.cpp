#include "../../include/headers.h"
void TestExtEucGCD()
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
        auto rst = ExtEucGCD(ab[i][0], ab[i][1]);
        printf("%2d: %d = %d*%d + %d*%d\n", i, 
            get<0>(rst), ab[i][0], get<1>(rst), ab[i][1], get<2>(rst));
    }
}