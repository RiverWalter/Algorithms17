int BinarySearch(int a[], int n, int x)
{
    int low = 0, high = n - 1, mid, p = -1;
    while (low <= high && p < 0) {
        mid = (low + high) / 2;
        if (x == a[mid]) 
            p = mid;
        else if (x < a[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return p;
}