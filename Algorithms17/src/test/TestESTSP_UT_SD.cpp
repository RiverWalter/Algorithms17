#include "../../include/headers.h"
void TestESTSP_UT_SD()
{
    int N0 = 8;
    char *cityNames[] =
    { "济南", "青岛", "淄博", "枣庄", "东营", "烟台", "潍坊", "济宁" };
    int distMat0[] = {
        3665, 1156, 2339, 2292, 4589, 2129, 1831, 
              2641, 4153, 2763, 2300, 1598, 4199, 
                    3123, 1277, 3574, 1114, 2698, 
                          4318, 6003, 3801, 1181, 
                                3477, 1283, 3977, 
                                      2538, 6062, 
                                            3817 };

    for (int i = 0; i < 1; i++)
    {
        switch (i)
        {
        case 0:
            TestESTSP_UT_N(N0, cityNames, distMat0);
            break;
        }
    }
}