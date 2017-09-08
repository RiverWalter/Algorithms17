#include "../../include/testheaders.h"

void TestPrimalTestTrialDivRange(int m, bool detail)
{
    for (int i = 3; i <= m; i++, i++)
    {
        if (detail)
            TestPrimalTestTrialDivDetail(i);
        else
            TestPrimalTestTrialDiv(i);
        printf("\n");
    }
}

void TestPrimalTestTrialDivDetail(int n)
{
    bool yes = true;
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            yes = false;
            break;
        }
        i++;
    }
    if (yes)
        printf("%d is a prime number.\n", n);
    else
        printf("%d = %d * %d is not a prime number.\n", n, i, n / i);
}

void TestPrimalTestTrialDiv(int n)
{
    bool yes = PrimalTestTrialDiv(n);
    if (yes)
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);
}