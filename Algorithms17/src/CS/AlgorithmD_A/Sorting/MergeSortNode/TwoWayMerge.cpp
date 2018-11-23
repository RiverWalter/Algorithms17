void TwoWayMerge(int a[], int p, int q, int r)
{
    int *b = new int[r + 1];
    int i = p, j = q + 1, k = p;
    while (i <= q && j <= r) {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    if (i == q + 1)
        for (; j <= r; j++)
            b[k++] = a[j];
    else
        for (; i<= q; i++)
            b[k++] = a[i];
    for (i = p; i <= r; i++)
        a[i] = b[i];
    delete b;
}
