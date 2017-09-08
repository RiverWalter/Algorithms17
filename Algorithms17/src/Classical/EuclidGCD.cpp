int EuclidGCD(int a, int b)
{
	int r;
	do {
		r = a % b;
		a = b;
		b = r;
	} while(r);
	return a;
}