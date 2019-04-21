//Pure language tests
#pragma warning(disable:4996)
#include "../../include/headers.h"
#include <sys\timeb.h>
#include <iostream>
#include <thread>
#include <vector>

void testString();
void testFor();
vector<vector<int>> a;

/////////
void basicTests()
{
    testFor();
	//testString();
    //printf("RAND_MAX = %d", RAND_MAX);
    ////test sizeof
    //int n;
    //printf("sizeof int = %d, size of n = %d", sizeof(int), sizeof(n));
}
void testFor()
{
    int i;
    for (i = 0; i < 5; i++);
    printf("i after for end: %d\n", i);
}
void testString()
{
	string s;
	printf("s.size: %zd\n", s.size());
	s.insert(s.cbegin(), '4');
	printf("4 s.size: %zd, %s\n", s.size(), s.c_str());
	s.insert(0, 1, '5');
	printf("5 s.size: %zd, %s\n", s.size(), s.c_str());
	s.insert(s.cbegin(), '6');
	printf("6 s.size: %zd, %s\n", s.size(), s.c_str());
}
void basicTestsA()
{
	//printf("RAND_MAX = %d", RAND_MAX);
	////test sizeof
	//int n;
	//printf("sizeof int = %d, size of n = %d", sizeof(int), sizeof(n));
}
void test2Darr()
{

}
void call_from_thread2(int i)
{
    std::cout << "Hello, World from a thread: " << i << std::endl;
}
void TestThread2()
{
    const int num_threads = 10;
    std::thread t[num_threads];
    for (int i = 0; i < num_threads; ++i) {
        t[i] = std::thread(call_from_thread2, i);
    }
    std::cout << "Launched from the main\n";
    //Join the threads with the main thread
    for (int i = 0; i < num_threads; ++i) {
        t[i].join();
    }
}

void call_from_thread1()
{
    std::cout << "Hello, World from a thread!" << std::endl;
}
void TestThread1()
{
    std::thread t1(call_from_thread1);
    t1.join();
}

void TestTimeb()
{
    struct timeb t_start; // , t_current;
    char timeStr[256];
    struct tm * timeinfo;
    //int t_diff;     
    for (int i = 0; i < 300; i++)
    {
        for (int k = 0; k < 2; k++)
        {
            for (int j = 0; j < 120; j++)
            {
                printf(".");
            }
            printf("\n");
        }
        ftime(&t_start);
        timeinfo = localtime(&t_start.time);
        strftime(timeStr, 255, "%Y.%m.%d %H:%M:%S", timeinfo);
        printf("Current time: %s.%d\n", timeStr, t_start.millitm);
    }
}
void Testfprintf()
{
    fprintf(stdout, "Hello world to stdout device!\n");
}
void test1Dto2D()
{
    int a[] = {
        11,22,
        33,44 };
    //int **b = (int **)a;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            printf("%3d", a[i * 2 + j]);
        printf("\n");
    }
}
void basicOutputTest()
{
    printf("Hello world!\n");
    auto n = 33;
    printf("n=%d\n", n);
    int a[] = { 22, 33, 44 };
    for (auto i : a)
        printf("%d\n", i);
    std::cout << "abc";
}