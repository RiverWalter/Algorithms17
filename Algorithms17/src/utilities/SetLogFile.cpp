#pragma warning(disable:4996)
#include "../../include/headers.h"
#include <direct.h>

FILE *logFP = stdout; 

void SetLogFile()
{
    struct timeb time_b;
    char *ymdhms = new char[20];
    char *logFileName = new char[50];
    struct tm * timeinfo;
    ftime(&time_b);
    timeinfo = localtime(&time_b.time);
    strftime(ymdhms, 20, "%Y%m%d%H%M%S", timeinfo);
    sprintf(logFileName, "output\\%s%03d.log", ymdhms, time_b.millitm);
    printf("Current time: %s.%d\n", ymdhms, time_b.millitm);
    printf("Log file name: %s\n", logFileName);
    
    //Ensure that the output directory exists.
    int r = _mkdir("output");
    printf("r=%d, errno=%d EEXIST=%d\n", r, errno, EEXIST);

    //Create the log file
    logFP = fopen(logFileName, "w+");
    fprintf(logFP, "Current time: %s.%d\n", ymdhms, time_b.millitm);
    fprintf(logFP, "Log file name: %s\n", logFileName);
}