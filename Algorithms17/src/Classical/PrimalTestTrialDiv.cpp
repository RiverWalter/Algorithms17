bool PrimalTestTrialDiv(int n)
{
    bool yes = true;
    int i = 2;
    while (i * i <= n)
    {
        if (n % i == 0)
        {
            yes = false;
            break;
        }
        i++;
    }
    return yes;
}