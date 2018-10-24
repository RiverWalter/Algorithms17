#include "../../include/headers.h"
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
