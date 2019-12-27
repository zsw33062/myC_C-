#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <pthread.h>
#include <algorithm>
#include <Windows.h>
using namespace std;

const long MAX = 10000L;  //数组中最大数
const long long MAX_NUM = 10000000L;  //排序数
const int thread = 2;       //线程数
const int thread_num = MAX_NUM / thread;  //每个线程排序的个数

int num[MAX_NUM];
int tmp_num[MAX_NUM];

pthread_barrier_t barrier;

/**
* Initialized Data
*/
void init(/*int *thread_num*/)
{
	/*int _num = 0;
	printf("Please enter the num of the thread:\n");
	scanf("%d", &_num);
	*thread_num = _num;*/
	srand((int)time(NULL));
	for (int i = 0; i < MAX_NUM; ++i)
		num[i] = rand() % MAX;
	//将初始化的数据放到本地名称为 result2.txt 里边
	FILE *fp = fopen("result1.txt", "w+");
	for (long long i = 0; i < MAX_NUM; ++i)
		fprintf(fp, "%ld ", num[i]);
}
//*快速排序函数
void qsorts(int *start, int *end)
{
	int nums = end - start;
	if (nums > 0)
	{
		int index = 0;
		int flag = start[0];
		int i = 0, j = nums;
		while (i != j)
		{
			while (j > i && start[j] >= flag)
				--j;
			start[index] = start[j];
			index = j;
			while (i < j && start[i] <= flag)
				++i;
			start[index] = start[i];
			index = i;
		}
		start[index] = flag;
		qsorts(start, start + (i - 1));
		qsorts(start + j + 1, end);
	}
}
void* work(void *arg)  //线程排序函数
{
	long index = (long)arg;
	// 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
	qsorts(num + index, num + index + thread_num - 1);
	pthread_barrier_wait(&barrier);
	pthread_exit(NULL);
	return NULL;		//加上 要不然 会报错
}

void meger()        //最终合并函数
{
	long index[thread];
	for (int i = 0; i < thread; ++i)
	{
		index[i] = i * thread_num;
	}

	for (long i = 0; i < MAX_NUM; ++i)
	{
		long min_index;
		long min_num = MAX;
		for (int j = 0; j < thread; ++j)
		{
			if ((index[j] < (j + 1) * thread_num)
				&& (num[index[j]] < min_num))
			{
				min_index = j;
				min_num = num[index[j]];
			}
		}
		tmp_num[i] = num[index[min_index]];
		index[min_index]++;
	}
}

int main(int argc, char const *argv[])
{
	//int _thread;
	int ret = 0;
	init(/*&_thread*/);
	Sleep(1000);
	clock_t start, end;
	//struct timeval start, end;	//不能用....
	pthread_t ptid;
	//定义线程的id 变量
	//printf("%ld %ld\n", num[1], num[2]);
	//gettimeofday(&start, NULL);			//不能用....
	start = clock();
	//init pthread and Thread barrier
	//add 1, total have (thread + 1) threads.
	pthread_barrier_init(&barrier, NULL, thread + 1);
	
	for (int i = 0; i < thread; ++i)
	{
		ret = pthread_create(&ptid, NULL, work, (void *)(i * thread_num));
		//参数依次是：创建的线程id，线程参数，调用的函数，传入的函数参数
		if (ret)
		{
			printf("Error:无法创建线程,%d\n", ret); 
			exit(-1);
		}
	}
	
	pthread_barrier_wait(&barrier);
	
	meger();
	/*gettimeofday(&end, NULL);
	long long s_usec = start.tv_sec * 1000000 + start.tv_usec;
	long long e_usec = end.tv_sec * 1000000 + end.tv_usec;*/

	end = clock();
	double useTime = (double)(end - start) /CLOCKS_PER_SEC;
	printf("use %d thread....\n",thread);
	printf("sort use %.6f seconds\n", useTime);
	//将排序好的数据放到本地名称为 result2.txt 里边
	FILE *fp = fopen("result2.txt", "w+");
	for (long long i = 0; i < MAX_NUM; ++i)
		fprintf(fp, "%ld ", num[i]);
	system("pause");
	return 0;
}