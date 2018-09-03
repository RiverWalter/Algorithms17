#include <stdio.h>
#include <stdlib.h>
using namespace std;
void GenParityCheck(int r, int c, unsigned int *d, int even)
{
    unsigned int mask, chbit;
    d[r] = 0;
    for (int i = 0; i < r; i++) {
        d[i] <<= 1;
        mask = 1;
        for (int j = 1; j < c + 1; j++)
        {
            mask <<= 1;
            chbit = (d[i] & mask) > 0;
            d[i] ^= chbit;
            d[r] ^= (chbit << j) + chbit;
        }
        if (!even)
            d[i] ^= 1;
    }
    printf("xx=%d\n", (1 << (c + 1)) - 1);
    if (!even)
    {
        d[r] ^= ((1 << (c + 1)) - 2);
        if (!(r & 1))
            d[r] ^= 1;
    }
}

void OutputParityCheck(int r, int c, unsigned int *d, int even)
{
    printf("\nParity check: r=%d, c=%d, even=%d\n\n", r, c, even);
    int mask;
    for (int i = 0; i < r + 1; i++) {
        printf("%5d: ", d[i] >> 1);
        mask = 1 << c;
        for (int j = 0; j < c + 1; j++)
        {
            printf("%d", (d[i] & mask) > 0);
            mask >>= 1;
        }
        printf("\n");
    }

}
int RandBits(int bits)
{
    int n = 1 << bits;
    return rand() % n;
}
void TestParityCheck(int r, int c, int even)
{
    unsigned int *d = new unsigned int[r + 1];
    for (int i = 0; i < r; i++)
        d[i] = RandBits(c);
    GenParityCheck(r, c, d, even);
    OutputParityCheck(r, c, d, even);
    delete d;
}
