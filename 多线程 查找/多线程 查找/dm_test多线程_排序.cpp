#include <stdio.h>  
#include <pthread.h>  
#include <assert.h>  

#pragma comment(lib, "pthreadVC2.lib")
#pragma comment(lib, "pthreadVCE2.lib")
typedef struct _qsort_parm
{
	int *array;
	int low;
	int high;
} qsort_parm_t;

/*分段*/
int partition(int *array, int low, int high)
{

	int pivot = *(array + low); //first element
	while (low < high)
	{
		while (low < high && array[high] >= pivot)
		{
			high--;
		}
		*(array + low) = *(array + high);
		while (low < high && array[low] <= pivot)
		{
			low++;
		}
		*(array + high) = *(array + low);
	}
	*(array + low) = pivot;
	return low;
}

/*线程执行函数*/
void* quicksort_worker(void *parm)
{
	pthread_t corpid;
	qsort_parm_t *iparm = (qsort_parm_t *)parm;
	int keypos = 0;
	qsort_parm_t qparm;
	void *ret;
	if (iparm->low < iparm->high)
	{
		/*分段*/
		keypos = partition(iparm->array, iparm->low, iparm->high);
		qparm.array = iparm->array;
		qparm.low = iparm->low;
		qparm.high = keypos - 1;

		/*创建子线程处理前半段*/
		pthread_create(&corpid, NULL, quicksort_worker, &qparm);
		iparm->low = keypos + 1;
		/*本线程处理后半段*/
		quicksort_worker(iparm);
		/*等待子线程结束*/
		pthread_join(corpid, &ret);
	}
	return NULL;
}


void* Function_t(void* Param)
{
	printf("我是线程！ ");
	pthread_t myid = pthread_self();
	printf("线程ID=%d ", myid);
	return NULL;
}
void quicksort_multithread(int *pA, int low, int high)
{
	qsort_parm_t qparm;
	qparm.array = pA;
	qparm.low = low;
	qparm.high = high;
	quicksort_worker(&qparm);
}
int maintest(void){
	int array[20] = { 9, 8, 0, 1, 4, 7, 6, 2, 3, 5, 19, 11, 18, 16, 10, 22, 38, 45, 14, 21 };

	int i = 0;
	quicksort_multithread(array, 0, 19);
	for (i = 0; i < 20; i++)
	{
		printf("%d ", array[i]);
	}

	getchar();
	return 0;
}