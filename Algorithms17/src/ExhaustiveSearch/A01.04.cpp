//Algorithm 1.4 (P5)(A01.04.cpp)
//����������(TSP), ��ٷ�(Exhaustion) 
#include "headers.h"
void findTSPMin(int **cityDist, int n, int *perm,
	int &minDist, int *minPath, bool verbose)
{
	int d=0, j;
	for (int i=0; i<n; i++) {
		j = (i+1) % n;
		if (cityDist[perm[i]][perm[j]] == Inf) {
			d = Inf;
			break;
		}
		d += cityDist[perm[i]][perm[j]];
	}
	if (d < minDist)  {
		minDist = d;
		for (int i=0; i<n; i++)
			minPath[i] = perm[i];
	}
	if (verbose) {
		for (int i=0; i<=n; i++)
			printf("%2c", 65 + perm[i % n]);
		if (d == Inf)
			printf("%4c", 'x');
		else
			printf("%4d", d);
		if (minDist == Inf)
			printf("%4c", 'x');
		else
			printf("%4d", minDist);
		printf("\n");
	}
}
void TSPExhaustion(int **cityDist, int i, int n, 
	int *perm, int &minDist, int *minPath, bool verbose)
{
	if (i == n-1)
		findTSPMin(cityDist, n, perm, minDist,
			minPath, verbose);
	else
		for (int j = i; j < n; j++) {
			swap((perm+i), (perm+j));
			TSPExhaustion(cityDist, i+1, n, perm,
				minDist, minPath, verbose);
			swap((perm+i), (perm+j)); //backtrack
		}
}
void TSPExhaustionTest(int n, bool verbose)
{
	int *minPath = new int[n];
	int minDist = Inf; //32767
	//��ʼ���������
	int **cityDist = new2DArr(n, n);
	randMatrix(cityDist, n, 2);
	//��ʼ���������б�
	int *perm = new int[n];
	for (int i=0; i<n; i++)
		perm[i] = i;
	printf("����TSP���ʽ����...\n");
	print2DArr(cityDist, n);
	printf("\n");
	TSPExhaustion(cityDist, 1, n, perm, 
		minDist, minPath, verbose);
	printf("���·����");
	for (int i=0; i<=n; i++)
		printf("%2c", 65 + minPath[i % n]);
	printf("\n���·�̣�%d\n", minDist);
	delete2DArr(cityDist, n);
	delete minPath;
	delete perm;
}
void TSPExhaustionTestEx5_2(bool verbose)
{
	int n = 4;
	int *minPath = new int[n];
	int minDist = Inf; //32767
	//��ʼ���������
	int **cityDist = Ex5_2aMatrix(n);
	//��ʼ���������б�
	int *perm = new int[n];
	for (int i=0; i<n; i++)
		perm[i] = i;
	printf("����TSP���ʽ����...\n");
	print2DArr(cityDist, n);
	printf("\n");
	TSPExhaustion(cityDist, 1, n, perm, 
		minDist, minPath, verbose);
	printf("���·����");
	for (int i=0; i<=n; i++)
		printf("%2c", 65 + minPath[i % n]);
	printf("\n���·�̣�%d\n", minDist);
	delete2DArr(cityDist, n);
	delete minPath;
	delete perm;
}
