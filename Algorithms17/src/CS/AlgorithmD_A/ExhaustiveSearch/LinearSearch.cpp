int LinearSearch(int a[], int n, int x)
{
    int p = 0;
    while ( p < n && x != a[p])
        p++;
    if (p == n)
        p = -1;
    return p;
}