#include "../../include/headers.h"
void LSEditDistCaller(const string &a, const string &b);
void TestLSEditDist()
{
	string a, b;
    a = "SUNNY";
	b = "SNOWY";
	LSEditDistCaller(a, b);
	a = "EXPONENTIAL"; 
	b = "POLYNOMIAL";
	LSEditDistCaller(a, b);
    a = "popular";
    b = "people";
    LSEditDistCaller(a, b);
    a = "water";
    b = "weather";
    LSEditDistCaller(a, b);
    a = "begin";
    b = "bargain";
    LSEditDistCaller(a, b);
    a = "event";
    b = "relevent";
    LSEditDistCaller(a, b);
    a = "concise";
    b = "coincidence";
    LSEditDistCaller(a, b);
    a = "friend";
    b = "difference";
    LSEditDistCaller(a, b);
    a = "coincidence";
    b = "conceive";
    LSEditDistCaller(a, b);
    a = "luminiscence";
    b = "sufficiency";
    LSEditDistCaller(a, b);
}
void LSEditDistCaller(const string &a, const string &b)
{
    vector<vector<int>> E;
    printf("String a: %s, b: %s\n", a.c_str(), b.c_str());
	printf("Distance: %d\n\n", LSEditDist(a, b, E));
    printf(" E  ");
    for (int j = 0; j < b.length(); j++)
        printf("%2c", b[j]);
    printf("\n");
    for (int i = 0; i <= a.length(); i++)
    {
        if (i == 0)
            printf("  ");
        else
            printf("%2c", a[i - 1]);
        for (int j = 0; j <= b.length(); j++)
        {
            printf("%2d", E[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}