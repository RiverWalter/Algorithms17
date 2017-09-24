#pragma warning(disable:4996)
#include "../../include/headers.h"
void GetDateTime(char *str)
{
    time_t rawtime;
    struct tm * timeinfo;

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(str, 100, "%Y.%m.%d %H:%M:%S", timeinfo);
}