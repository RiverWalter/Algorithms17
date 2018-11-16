int EuclidGCD(int a, int b)
{
	int r;
    while (b) {
		r = a % b;
		a = b;
		b = r;
	} 
	return a;
}