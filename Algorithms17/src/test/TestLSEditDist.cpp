#include "../../include/headers.h"
void LSEditDistCaller(const string &a, const string &b);
void TestLSEditDist()
{
	string a, b;
	a = "snowy";
	b = "sunny";
	LSEditDistCaller(a, b);
	a = "polynomial"; 
	b = "exponential";
	LSEditDistCaller(a, b);
}
void LSEditDistCaller(const string &a, const string &b)
{
	printf("String a: %s, b: %s\n", a.c_str(), b.c_str());
	printf("Distance: %d\n\n", LSEditDist(a, b));
}