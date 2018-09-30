int BinarySearchR(int a[], int low, int high, int x)
{
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (a[mid] > x)
        return BinarySearchR(a, low, mid - 1, x);
    else if (a[mid] == x)
        return mid;
    else
        return BinarySearchR(a, mid + 1, high, x);
}

