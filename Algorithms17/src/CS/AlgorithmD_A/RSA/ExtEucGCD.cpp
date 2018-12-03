#include <tuple>
using namespace std;
tuple<int, int, int>ExtEucGCD(int a, int b)
{
    auto rst_k = make_tuple(a, 1, 0);
    auto rst_k1 = make_tuple(b, 0, 1);
    int q, p;
    while (get<0>(rst_k1) != 0)
    {
        q = get<0>(rst_k) / get<0>(rst_k1);
        p = get<0>(rst_k);
        get<0>(rst_k) = get<0>(rst_k1);
        get<0>(rst_k1) = p - q * get<0>(rst_k1);
        p = get<1>(rst_k);
        get<1>(rst_k) = get<1>(rst_k1);
        get<1>(rst_k1) = p - q * get<1>(rst_k1);
        p = get<2>(rst_k);
        get<2>(rst_k) = get<2>(rst_k1);
        get<2>(rst_k1) = p - q * get<2>(rst_k1);
    }
    return rst_k;
}

