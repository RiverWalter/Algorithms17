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
    b = "wheat";
    LSEditDistCaller(a, b);
    a = "begins";
    b = "bargain";
    LSEditDistCaller(a, b);
    a = "servant";
    b = "reveal";
    LSEditDistCaller(a, b);
    a = "concise";
    b = "receives";
    LSEditDistCaller(a, b);
    a = "friend";
    b = "difference";
    LSEditDistCaller(a, b);
    a = "coincides";
    b = "conceive";
    LSEditDistCaller(a, b);
    a = "luminiscence";
    b = "sufficiency";
    LSEditDistCaller(a, b);
   
    a = "efficiency";
    b = "fiercely";
    LSEditDistCaller(a, b);
    a = "there";
    b = "hear";
    LSEditDistCaller(a, b);
    a = "defence";
    b = "disern";
    LSEditDistCaller(a, b);
    a = "befriend";
    b = "different";
    LSEditDistCaller(a, b);
    a = "brand";
    b = "reread";
    LSEditDistCaller(a, b);
    a = "teachers";
    b = "nearest";
    LSEditDistCaller(a, b);
    a = "veteran";
    b = "wheaten";
    LSEditDistCaller(a, b);
}
