#include "../../include/headers.h"
void TestESTSP_UT_FA()
{
    int N0 = 4;
    int distMat0[] = {
        3, 5, 2,
        9,10,
        1 };

    int N1 = 5;
    int distMat1[] = {
        3, 4, 2, 7,
        4, 6, 3,
        5, 8,
        6 };

    int N2 = 5;
    int distMat2[] = {
        10,Inf,  4, 12,
        15,  8,  5,
        7, 30,
        6 };

    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            TestESTSP_UT_F(N0, distMat0);
            break;
        case 1:
            TestESTSP_UT_F(N1, distMat1);
            break;
        case 2:
            TestESTSP_UT_F(N2, distMat2);
            break;
        }
    }
}