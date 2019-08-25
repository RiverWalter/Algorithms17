int EuclidGCDR(int a, int b)
{
	if (b == 0)
		return a;
	else
		return EuclidGCDR(b, a % b);
}


